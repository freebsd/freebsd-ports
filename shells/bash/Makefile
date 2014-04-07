# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=		bash
PATCHLEVEL=		8
PORTVERSION=		4.3.${PATCHLEVEL:S/^0//g}
PORTREVISION?=		0
CATEGORIES=		shells
MASTER_SITES=		GNU
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION:R}
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

OPTIONS_DEFINE=		IMPLICITCD COLONBREAKSWORDS HELP NLS STATIC SYSLOG DOCS
OPTIONS_DEFAULT=	IMPLICITCD COLONBREAKSWORDS HELP NLS
IMPLICITCD_DESC=	Use directory name alone to cd into it
COLONBREAKSWORDS_DESC=	Colons break words
HELP_DESC=		Enable builtin help

USES=			bison
OPTIONS_SUB=		yes

IMPLICITCD_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-implicitcd
COLONBREAKSWORDS_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-colonbreakswords

HELP_CONFIGURE_ENABLE=	help-builtin
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext iconv

INFO=			bash

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=		yes

PORTDOCS=		FAQ INTRO CHANGES COMPAT NEWS POSIX RBASH README \
			bash.html bashref.html

CONFIGURE_ARGS+=	--without-bash-malloc \
			--disable-rpath \
			--enable-disabled-builtins

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC} || defined(NO_DYNAMICROOT) || (defined(NOSHARED) && ${NOSHARED:L} != "no")
CONFIGURE_ARGS+=	--enable-static-link
PKGNAMESUFFIX=		-static
CONFLICTS+=		bash-[0-9]*
.else
CONFIGURE_ARGS+=	--disable-static-link
CONFLICTS+=		bash-static-[0-9]*
.endif

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
	@${REINPLACE_CMD} -e "s|#define HAVE_ICONV 1|#undef HAVE_ICONV|g" \
		${WRKSRC}/config.h
.endif

pre-build:
	@${ECHO_CMD} $$((${PORTREVISION}-1)) > ${WRKSRC}/.build

post-install:
	${LN} -sf bash ${STAGEDIR}${PREFIX}/bin/rbash
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ \
		${WRKSRC}/doc/INTRO ${STAGEDIR}${DOCSDIR}
	for d in ${PORTDOCS:NFAQ:NINTRO:N*html}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${STAGEDIR}${DOCSDIR}; \
	done

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
