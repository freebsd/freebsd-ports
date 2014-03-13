# Created by: torstenb
# $FreeBSD$

PORTNAME=	zsh
PORTVERSION=	5.0.5
CATEGORIES=	shells
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		SF/${PORTNAME}/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	The Z shell

LICENSE=	ZSH
LICENSE_NAME=	ZSH license
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_UNSAFE=	yes

ZSH_VER=	${PORTVERSION}

USES=		iconv ncurses tar:bzip2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-term-lib="ncursesw ncurses" --with-tcsetpgrp \
		--enable-function-subdirs

EXTRA_PATCHES=	${FILESDIR}/extra-patch-bsdtar
#EXTRA_COMPLETION_FILES=	_sockstat
#EXTRA_COMPLETION_DIR=	Completion/BSD/Command

OPTIONS_DEFINE=	GDBM MEM SECURE_FREE MAILDIR MULTIBYTE PCRE STATIC DOCS DEBUG \
		EXAMPLES
OPTIONS_DEFAULT=	SECURE_FREE MAILDIR MULTIBYTE

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
MULTIBYTE_CONFIGURE_ENABLE=	multibyte

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO=	zsh
.endif

post-patch:
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
	cd ${WRKSRC} && /usr/bin/soelim ${WRKSRC}/Doc/zshall.1.source > \
		${WRKSRC}/Doc/zshall.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/info
	makeinfo --no-split --output=${WRKSRC}/Doc/zsh.info \
		${WRKSRC}/Doc/zsh.texi
.endif

post-install:
	${LN} -f ${STAGEDIR}${PREFIX}/bin/zsh ${STAGEDIR}${PREFIX}/bin/rzsh
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/StartupFiles && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/zsh.info ${STAGEDIR}${PREFIX}/info/zsh.info
.endif
	${STAGEDIR}${PREFIX}/bin/zsh -fc ' \
		setopt extendedglob nomark_dirs; \
		for i in ${STAGEDIR}${DATADIR}/${ZSH_VER}/functions/**/*(/) ; do \
			zcompile -U -M $$i.zwc $$i/*~*.zwc(^/) ; \
			${CHMOD} 644 $$i.zwc ; \
		done'

regression-test:
	@cd ${WRKSRC}; ${SETENV} -i ${MAKE} check



.include <bsd.port.mk>
