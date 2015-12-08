# Created by: torstenb
# $FreeBSD$

PORTNAME=	zsh
DISTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	\
		http://www.zsh.org/pub/:doc \
		http://www.zsh.org/pub/ \
		SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		SF/${PORTNAME}/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Z shell

LICENSE=	ZSH
LICENSE_NAME=	ZSH license
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_UNSAFE=	yes

ZSH_VER=	${PORTVERSION}

USES=		iconv ncurses shebangfix tar:xz
SHEBANG_FILES=	Functions/Calendar/calendar_add \
		Functions/Misc/checkmail \
		Functions/Misc/run-help \
		Functions/Misc/sticky-note \
		Functions/Misc/zcalc \
		Functions/Misc/zed \
		Functions/Misc/zkbd
SHEBANG_LANG=	zsh
zsh_OLD_CMD=	/bin/zsh
zsh_CMD=	${PREFIX}/bin/zsh
GNU_CONFIGURE=	yes
TEST_TARGET=	test

CPPFLAGS+=	-I${LOCALBASE}/include -DBOOL_DEFINED
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed
CONFIGURE_ENV+=	zsh_cv_sys_path_dev_fd=no
CONFIGURE_ARGS=	--with-term-lib="ncursesw ncurses" --with-tcsetpgrp \
		--enable-function-subdirs --enable-multibyte \
		--sysconfdir=${PREFIX}/etc

EXTRA_PATCHES=	${FILESDIR}/extra-patch-bsdtar
#EXTRA_COMPLETION_FILES=	_sockstat
#EXTRA_COMPLETION_DIR=	Completion/BSD/Command

OPTIONS_DEFINE=	GDBM MEM SECURE_FREE MAILDIR PCRE STATIC DOCS DEBUG \
		EXAMPLES
OPTIONS_DEFAULT=	SECURE_FREE MAILDIR

GDBM_DESC=	Enable GDBM support (GPL)
MEM_DESC=	Enable zsh-mem options
SECURE_FREE_DESC=	Enable zsh-secure-free
MAILDIR_DESC=	Enable support for Maildirs in MAIL(PATH)

PLIST_SUB+=	ZSH_VER="${ZSH_VER}"

DOCS=		LICENCE META-FAQ README Etc/BUGS Etc/CONTRIBUTORS Etc/FAQ \
		Etc/completion-style-guide Doc/zsh*.html Doc/zsh.dvi
PORTDOCS=	*
PORTEXAMPLES=	zlogin zshenv zshrc

OPTIONS_SUB=	yes

DOCS_DISTFILES=		${DISTNAME}-doc${EXTRACT_SUFX}:doc
GDBM_LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm
GDBM_CONFIGURE_ENABLE=	gdbm
PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PCRE_CONFIGURE_ENABLE=	pcre
MEM_CONFIGURE_ENABLE=	zsh-mem
SECURE_FREE_CONFIGURE_ENABLE=	zsh-secure-free
MAILDIR_CONFIGURE_ENABLE=	maildir-support
STATIC_LDFLAGS=		-static
STATIC_CONFIGURE_ON=	--disable-dynamic
STATIC_CONFIGURE_OFF=	--enable-dynamic
DEBUG_CONFIGURE_ENABLE=	zsh-debug

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_lib_iconv_libiconv=no
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e '1s|zsh|${zsh_CMD}|' ${WRKSRC}/Functions/Misc/run-help-ip
	@${REINPLACE_CMD} -e '/LIBS/s/-lrt//' ${WRKSRC}/configure
	@${SED} -i "" -e "s,link=dynamic,link=either," \
		${WRKSRC}/Src/Modules/*.mdd
	@${SED} -i "" -e "s,/etc/,${LOCALBASE}/etc/," \
		${WRKSRC}/Functions/MIME/zsh-mime-setup
.ifdef EXTRA_COMPLETION_FILES
	@${ECHO} "===>  Installing extra completion files"
.for COMPFILE in ${EXTRA_COMPLETION_FILES}
	@(if [ -f ${WRKSRC}/${EXTRA_COMPLETION_DIR}/${COMPFILE} ] ; then \
		${ECHO} "${EXTRA_COMPLETION_DIR}/${COMPFILE} already exists" ; \
		exit 1 ; \
	else \
		${ECHO} ${EXTRA_COMPLETION_DIR}/${COMPFILE} ; \
		${CP} ${FILESDIR}/${COMPFILE} \
			${WRKSRC}/${EXTRA_COMPLETION_DIR}/${COMPFILE} ; \
	fi)
.endfor
.endif
	@${FIND} ${WRKSRC}/Completion -type f -iname '*.orig' -delete

post-build:
	# Fix ".so" macro problem by using "soelim" command.
	${LN} -sf ${WRKSRC}/Doc ${WRKSRC}/man1
	${MV} ${WRKSRC}/Doc/zshall.1 ${WRKSRC}/Doc/zshall.1.source
	cd ${WRKSRC} && ${SOELIM} -r ${WRKSRC}/Doc/zshall.1.source > \
		${WRKSRC}/Doc/zshall.1

post-install:
	${LN} -f ${STAGEDIR}${PREFIX}/bin/zsh ${STAGEDIR}${PREFIX}/bin/rzsh
	${STAGEDIR}${PREFIX}/bin/zsh -fc ' \
		setopt extendedglob nomark_dirs; \
		cd ${STAGEDIR}/${DATADIR}/${ZSH_VER} ; \
		for i in functions/**/*(/) ; do \
			zcompile -U -M $$i.zwc $$i/*~*.zwc(^/) ; \
			${CHMOD} 644 $$i.zwc ; \
		done'

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/StartupFiles && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

regression-test:
	@cd ${WRKSRC}; ${SETENV} -i ${MAKE} check

.include <bsd.port.post.mk>
