# Created by: torstenb
# $FreeBSD$

PORTNAME=	zsh
DISTVERSION=	5.2
PORTREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	http://www.zsh.org/pub/:doc \
		http://www.zsh.org/pub/ \
		SF \
		SF/${PORTNAME}/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	The Z shell

LICENSE=	ZSH
LICENSE_NAME=	ZSH license
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_UNSAFE=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-bsdtar
ZSH_VER=	${PORTVERSION}
PLIST_SUB+=	ZSH_VER="${ZSH_VER}"
SUB_FILES=	pkg-message

USES=		iconv ncurses shebangfix tar:xz

SHEBANG_LANG=	zsh
zsh_OLD_CMD=	/bin/zsh
zsh_CMD=	${PREFIX}/bin/zsh
SHEBANG_FILES=	Functions/Calendar/calendar_add \
		Functions/Misc/checkmail \
		Functions/Misc/run-help \
		Functions/Misc/sticky-note \
		Functions/Misc/zcalc \
		Functions/Misc/zed \
		Functions/Misc/zkbd

GNU_CONFIGURE=	yes
TEST_TARGET=	test

CPPFLAGS+=	-I${LOCALBASE}/include -DBOOL_DEFINED
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed
CONFIGURE_ENV+=	zsh_cv_sys_path_dev_fd=no
CONFIGURE_ARGS=	--with-tcsetpgrp \
		--enable-function-subdirs \
		--enable-multibyte \
		--sysconfdir=${PREFIX}/etc

DOCS=		LICENCE META-FAQ README \
		Etc/BUGS Etc/CONTRIBUTORS Etc/FAQ Etc/completion-style-guide \
		Doc/zsh*.html Doc/zsh.dvi

PORTDOCS=	*
PORTEXAMPLES=	zlogin zshenv zshrc

## Vendor completions to be added into the port (none used now)
#EXTRA_COMPLETION_FILES=	_sockstat
#EXTRA_COMPLETION_DIR=	Completion/BSD/Command

OPTIONS_DEFINE=	DEBUG ETCDIR GDBM MAILDIR MEM PCRE SECURE_FREE STATIC \
		DOCS EXAMPLES
OPTIONS_DEFAULT=SECURE_FREE MAILDIR
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	zsh-debug

DOCS_DISTFILES=	${DISTNAME}-doc${EXTRACT_SUFX}:doc

GDBM_DESC=		Enable GDBM support (GPL)
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_ENABLE=	gdbm

ETCDIR_DESC=		System-wide defaults in /etc (instead of $${PREFIX}/etc)
ETCDIR_CONFIGURE_OFF=	--enable-etcdir=${PREFIX}/etc

MAILDIR_DESC=			Enable support for Maildirs in MAIL(PATH)
MAILDIR_CONFIGURE_ENABLE=	maildir-support

MEM_DESC=		Enable zsh-mem options
MEM_CONFIGURE_ENABLE=	zsh-mem

SECURE_FREE_DESC=		Enable zsh-secure-free
SECURE_FREE_CONFIGURE_ENABLE=	zsh-secure-free

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_ENABLE=	pcre

## Some modules can only be built dynamically (such as the regex module).
## If you enable STATIC, you may get strange errors if scripts/plugins
## try to use the regex module.
STATIC_LDFLAGS=		-static
STATIC_CONFIGURE_ON=	--disable-dynamic --with-term-lib="tinfow tinfo"
STATIC_CONFIGURE_OFF=	--enable-dynamic  --with-term-lib="ncursesw ncurses"

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

# Adding vendor completions into the package
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
	(cd ${WRKSRC} && ${SOELIM} -r ${WRKSRC}/Doc/zshall.1.source > \
		${WRKSRC}/Doc/zshall.1)

post-install:
	${LN} -f ${STAGEDIR}${PREFIX}/bin/zsh ${STAGEDIR}${PREFIX}/bin/rzsh
# Precompile completions and functions
	(${STAGEDIR}${PREFIX}/bin/zsh -fc ' \
		setopt extendedglob nomark_dirs; \
		cd ${STAGEDIR}/${DATADIR}/${ZSH_VER} ; \
		for i in functions/**/*(/) ; do \
			zcompile -U -M $$i.zwc $$i/*~*.zwc(^/) ; \
			${CHMOD} 644 $$i.zwc ; \
		done')

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/StartupFiles && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
