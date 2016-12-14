# Created by: torstenb
# $FreeBSD$

PORTNAME=	zsh
DISTVERSION=	5.3
CATEGORIES=	shells
MASTER_SITES=	http://www.zsh.org/pub/ \
		SF \
		http://www.zsh.org/pub/:doc \
		SF/${PORTNAME}/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	The Z shell

LICENSE=	ZSH
LICENSE_NAME=	ZSH license
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_UNSAFE=	yes

USES=		iconv ncurses shebangfix tar:xz

SHEBANG_LANG=	zsh
zsh_OLD_CMD=	zsh	# shebang appears as /bin/zsh and just zsh
SHEBANG_FILES=	Functions/Calendar/* \
		Functions/Misc/*

CONFIGURE_ARGS=	--with-tcsetpgrp \
		--enable-function-subdirs \
		--enable-maildir-support \
		--enable-multibyte \
		--enable-zsh-secure-free \
		--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV+=	zsh_cv_sys_path_dev_fd=no

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DBOOL_DEFINED
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--as-needed
TEST_TARGET=	test

OPTIONS_DEFINE=	DEBUG ETCDIR GDBM MEM PCRE STATIC \
		DOCS EXAMPLES
OPTIONS_SUB=	yes

ETCDIR_DESC=	System-wide defaults in /etc (instead of $${PREFIX}/etc)
GDBM_DESC=	Enable GDBM support (GPL)
MEM_DESC=	Enable zsh-mem options

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

DEBUG_CONFIGURE_ENABLE=	zsh-debug
ETCDIR_CONFIGURE_OFF=	--enable-etcdir=${PREFIX}/etc
GDBM_CONFIGURE_ENABLE=	gdbm
MEM_CONFIGURE_ENABLE=	zsh-mem
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

PORTDOCS=	*
PORTEXAMPLES=	zlogin zshenv zshrc

ZSH_VER=	${PORTVERSION}
PLIST_SUB+=	ZSH_VER="${ZSH_VER}"
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ENV+=	ac_cv_lib_iconv_libiconv=no
.endif

post-patch:
# FreeBSD's clock_gettime(2) is in libc, not librt; see PR 167857
	@${REINPLACE_CMD} -e '/LIBS/s|-lrt||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|/etc/|${LOCALBASE}/etc/|" \
		${WRKSRC}/Functions/MIME/zsh-mime-setup

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
