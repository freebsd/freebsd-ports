# Created by: torstenb

PORTNAME=	zsh
DISTVERSION=	5.8
CATEGORIES=	shells
MASTER_SITES=	https://www.zsh.org/pub/ \
		SF \
		https://www.zsh.org/pub/:doc \
		SF/${PORTNAME}/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	The Z shell

LICENSE=	ZSH
LICENSE_NAME=	ZSH license
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf cpe iconv localbase:ldflags ncurses shebangfix \
		tar:xz

SHEBANG_FILES=	Functions/Calendar/* Functions/Misc/*
SHEBANG_LANG=	zsh
zsh_OLD_CMD=	zsh # shebang appears as /bin/zsh and just zsh

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-function-subdirs \
			--enable-maildir-support \
			--enable-multibyte \
			--enable-zsh-secure-free \
			--sysconfdir=${PREFIX}/etc \
			--with-tcsetpgrp
# fix PREFIX != LOCALBASE
CONFIGURE_ARGS+=	--disable-site-fndir \
			--enable-additional-fpath=${DATADIR}/site-functions
CONFIGURE_ENV+=		ac_cv_header_sys_capability_h=no \
			zsh_cv_sys_path_dev_fd=no

MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	test

CPPFLAGS+=	-DBOOL_DEFINED
LDFLAGS+=	-Wl,--as-needed

SUB_FILES=	pkg-message

PLIST_SUB+=	ZSH_VER="${ZSH_VER}"
PORTDOCS=	*

OPTIONS_DEFINE=	BASE_ZSH DEBUG DOCS ETCDIR EXAMPLES GDBM MEM PCRE STATIC
OPTIONS_SUB=	yes

BASE_ZSH_DESC=	Make zsh and rzsh also available as /bin/zsh and /bin/rzsh
ETCDIR_DESC=	System-wide defaults in /etc (instead of $${PREFIX}/etc)
GDBM_DESC=	Enable GDBM support (GPL)
MEM_DESC=	Enable zsh-mem options

DEBUG_CONFIGURE_ENABLE=	zsh-debug
DOCS_DISTFILES=		${DISTNAME}-doc${EXTRACT_SUFX}:doc
ETCDIR_CONFIGURE_OFF=	--enable-etcdir=${PREFIX}/etc
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_ENABLE=	gdbm
MEM_CONFIGURE_ENABLE=	zsh-mem
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_ENABLE=	pcre

## Some modules can only be built as a shared library.
## If you enable STATIC, you may get strange errors if you, a script,
## or a plugin tries to use the regex module.
STATIC_CONFIGURE_ON=	--disable-dynamic \
			--with-term-lib="tinfow tinfo"
STATIC_CONFIGURE_OFF=	--enable-dynamic \
			--with-term-lib="ncursesw ncurses"
STATIC_LDFLAGS=		-static

DOCS=		LICENCE META-FAQ README Etc/BUGS Etc/CONTRIBUTORS Etc/FAQ \
		Etc/completion-style-guide Doc/zsh*.html Doc/zsh.dvi

PORTEXAMPLES=	zlogin zshenv zshrc

ZSH_VER=	${PORTVERSION}

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_lib_iconv_libiconv=no
.endif

.if ${ncurses_ARGS} == port
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-Src_Modules_curses__keys.awk
.endif

post-patch:
# FreeBSD's clock_gettime(2) is in libc, not librt; see PR 167857
	@${REINPLACE_CMD} -e '/LIBS/s|-lrt||' ${WRKSRC}/configure
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

post-install-BASE_ZSH-on:
	@${MKDIR} ${STAGEDIR}/bin
.for f in zsh rzsh
	${RLN} ${STAGEDIR}${PREFIX}/bin/${f} ${STAGEDIR}/bin/${f}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/StartupFiles && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
