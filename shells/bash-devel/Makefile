# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=		bash
PATCHLEVEL=		45
PORTVERSION=		4.2.${PATCHLEVEL:S/^0//g}
PORTREVISION?=		1
CATEGORIES=		shells
MASTER_SITES=		GNU
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION:R}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=		${MASTER_SITE_GNU} \
			ftp://ftp.cwru.edu/pub/%SUBDIR%/
PATCH_SITE_SUBDIR=	${PORTNAME}/${DISTNAME}-patches/
PATCHFILES!=		/usr/bin/jot -s " " -w \
			${PORTNAME}${PORTVERSION:R:S/.//g}-%03d \
			${PATCHLEVEL} 1 ${PATCHLEVEL}

MAINTAINER=		ehaupt@FreeBSD.org
COMMENT=		The GNU Project's Bourne Again SHell

LICENSE=		GPLv3

OPTIONS_DEFINE=	IMPLICITCD COLONBREAKSWORDS HELP NLS STATIC SYSLOG DOCS
OPTIONS_DEFAULT=IMPLICITCD COLONBREAKSWORDS HELP NLS
IMPLICITCD_DESC=	Use directory name alone to cd into it
COLONBREAKSWORDS_DESC=	Colons break words
HELP_DESC=		Enable builtin help

USES=			bison

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMPLICITCD}
EXTRA_PATCHES+=		${PATCHDIR}/extrapatch-implicitcd
.endif

.if ${PORT_OPTIONS:MCOLONBREAKSWORDS}
EXTRA_PATCHES+=		${PATCHDIR}/extrapatch-colonbreakswords
.endif

INFO=			bash

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=		yes

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=		FAQ INTRO CHANGES COMPAT NEWS POSIX RBASH
.endif

CONFIGURE_ARGS=		--without-bash-malloc \
			--disable-rpath \
			--enable-disabled-builtins

.if ${PORT_OPTIONS:MSTATIC} || defined(NO_DYNAMICROOT) || (defined(NOSHARED) && ${NOSHARED:L} != "no")
CONFIGURE_ARGS+=	--enable-static-link
PKGNAMESUFFIX=		-static-devel
CONFLICTS+=		bash-[0-9]* bash-static-[0-9]* bash-devel-[0-9]*
.else
CONFIGURE_ARGS+=	--enable-static-link=no
PKGNAMESUFFIX=		-devel
CONFLICTS+=		bash-static-[0-9]* bash-[0-9]* bash-static-devel-[0-9]*
.endif

.if empty(PORT_OPTIONS:MHELP)
CONFIGURE_ARGS+=	--disable-help-builtin
.endif

.if empty(PORT_OPTIONS:MNLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USES+=			gettext iconv
PLIST_SUB+=		NLS=""
.endif

CPPFLAGS+=		${PTHREAD_CFLAGS} \
			-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ENV=		YACC="bison -y"

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/bash.1
.if ${PORT_OPTIONS:MSYSLOG}
	@${REINPLACE_CMD} \
	    -e "s|/\*.*#define SYSLOG_HISTORY .*\*/|#define SYSLOG_HISTORY|g" \
	    ${WRKSRC}/config-top.h
.endif
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e "s|@LIBICONV@||g" ${WRKSRC}/Makefile.in
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|"
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e "s|#define HAVE_ICONV 1|#undef HAVE_ICONV|g" ${WRKSRC}/config.h
.endif

pre-build:
	@${ECHO_CMD} $$((${PORTREVISION}-1)) > ${WRKSRC}/.build

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin ; ${LN} -sf bash rbash
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ \
		${WRKSRC}/doc/INTRO ${STAGEDIR}${DOCSDIR}
	@for d in ${PORTDOCS:NFAQ:NINTRO}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${STAGEDIR}${DOCSDIR}; \
	done
.endif

regress: build
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test

ckp:
	${MAKE} -DPATCH_DEBUG clean patch

# requires ftp/ncftp3
cklatest:
	@${ECHO} -n "Currently at: "
	@${MAKE} -V PATCHLEVEL
	-ncftpls \
	    ftp://ftp.cwru.edu/pub/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/\.[0-9a-z]*$//}-patches/ \
		| fgrep -v .sig | ${TAIL}

.include <bsd.port.mk>
