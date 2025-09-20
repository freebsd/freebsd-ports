PORTNAME=	zsh
DISTVERSION=	5.9
PORTREVISION=	5
CATEGORIES=	shells
MASTER_SITES=	https://www.zsh.org/pub/ \
		SF \
		https://www.zsh.org/pub/:doc \
		SF/${PORTNAME}/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	The Z shell
WWW=		https://www.zsh.org/

LICENSE=	ZSH
LICENSE_NAME=	ZSH license
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_UNSAFE=	yes

USES=		cpe iconv localbase:ldflags ncurses perl5 shebangfix tar:xz

USE_PERL5=	build
SHEBANG_LANG=	zsh
zsh_OLD_CMD=	zsh	# shebang appears as /bin/zsh and just zsh
SHEBANG_FILES=	Functions/Calendar/* \
		Functions/Misc/* \
		Functions/VCS_Info/*

CONFIGURE_ARGS=	--with-tcsetpgrp \
		--enable-function-subdirs \
		--enable-maildir-support \
		--enable-multibyte \
		--enable-zsh-secure-free \
		--sysconfdir=${PREFIX}/etc

# fix PREFIX != LOCALBASE
CONFIGURE_ARGS+=--disable-site-fndir \
		--enable-additional-fpath=${DATADIR}/site-functions

CONFIGURE_ENV+=	zsh_cv_sys_path_dev_fd=no \
		ac_cv_header_sys_capability_h=no \
		zsh_cv_path_utmpx=/var/run/utx.active

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPPFLAGS+=	-DBOOL_DEFINED
LDFLAGS+=	-Wl,--as-needed
TEST_TARGET=	test

OPTIONS_DEFINE=	DEBUG ETCDIR GDBM PCRE STATIC \
		DOCS EXAMPLES
OPTIONS_SUB=	yes

ETCDIR_DESC=	System-wide defaults in /etc (instead of $${PREFIX}/etc)
GDBM_DESC=	Enable GDBM support (GPL)

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

DEBUG_CONFIGURE_ENABLE=	zsh-debug
ETCDIR_CONFIGURE_OFF=	--enable-etcdir=${PREFIX}/etc
GDBM_CONFIGURE_ENABLE=	gdbm
PCRE_CONFIGURE_ENABLE=	pcre

## Some modules can only be built as a shared library.
## If you enable STATIC, you may get strange errors if you, a script,
## or a plugin tries to use the regex module.
STATIC_LDFLAGS=		-static
STATIC_CONFIGURE_ON=	--disable-dynamic --with-term-lib="tinfow tinfo"
STATIC_CONFIGURE_OFF=	--enable-dynamic  --with-term-lib="ncursesw ncurses"

DOCS=		LICENCE META-FAQ README \
		Etc/BUGS Etc/CONTRIBUTORS Etc/FAQ Etc/completion-style-guide \
		Doc/zsh*.html Doc/zsh.dvi
DOCS_DISTFILES=	${DISTNAME}-doc${EXTRACT_SUFX}:doc
DOCS_CONFIGURE_OFF=	--enable-runhelpdir=no

PORTDOCS=	*
PORTEXAMPLES=	zlogin zshenv zshrc

ZSH_VER=	${DISTVERSION}
PLIST_SUB+=	ZSH_VER="${ZSH_VER}"
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_lib_iconv_libiconv=no
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/|${LOCALBASE}/etc/|" \
		${WRKSRC}/Functions/MIME/zsh-mime-setup
	${RM} ${WRKSRC}/Doc/help.txt

post-patch-STATIC-on:
	@${REINPLACE_CMD} -e "s|link=dynamic|link=either|" \
		${WRKSRC}/Src/Modules/*.mdd

post-build:
# Fix ".so" macro problem by using "soelim" command.
# soelim needs the manpages in man1/
	${LN} -sf ${WRKSRC}/Doc ${WRKSRC}/man1
	${MV} ${WRKSRC}/Doc/zshall.1 ${WRKSRC}/Doc/zshall.1.source
	(cd ${WRKSRC} && ${SOELIM} -r ${WRKSRC}/Doc/zshall.1.source > \
		${WRKSRC}/Doc/zshall.1)

post-install:
	${INSTALL_DATA} ${FILESDIR}/_mdo \
		${STAGEDIR}/${DATADIR}/${ZSH_VER}/functions/Completion/Unix/
	${MKDIR} ${STAGEDIR}${DATADIR}/site-functions
	${LN} -f ${STAGEDIR}${PREFIX}/bin/zsh ${STAGEDIR}${PREFIX}/bin/rzsh
# Precompile completions and functions
	(${STAGEDIR}${PREFIX}/bin/zsh -fc ' \
		setopt extendedglob nomark_dirs; \
		cd ${STAGEDIR}/${DATADIR}/${ZSH_VER} ; \
		rm -f functions/**/*.orig ; \
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
