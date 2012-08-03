# ex:ts=8
# New ports collection makefile for:    bash3
# Date created:				30 Jul 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		bash
PATCHLEVEL=		37
PORTVERSION=		4.2.${PATCHLEVEL:S/^0//g}
PORTREVISION?=		0
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GNU:S/$/:bash/} \
			ftp://ftp.cwru.edu/pub/%SUBDIR%/:faq
MASTER_SITE_SUBDIR=	${PORTNAME}/:bash,faq
DISTNAME=		${PORTNAME}-${PORTVERSION:R}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}:bash
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=		${MASTER_SITE_GNU} \
			ftp://ftp.cwru.edu/pub/%SUBDIR%/
PATCH_SITE_SUBDIR=	${PORTNAME}/${DISTNAME}-patches/
PATCHFILES!=		/usr/bin/jot -s " " -w \
			${PORTNAME}${PORTVERSION:R:S/.//g}-%03d \
			${PATCHLEVEL} 1 ${PATCHLEVEL}

MAINTAINER=		obrien@FreeBSD.org
COMMENT=		The GNU Project's Bourne Again SHell

IGNOREFILES=		FAQ

.if defined(WITH_OPTIONS) || defined(WITH_BASH_OPTIONS)
.include "${.CURDIR}/../bash/options"
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMPLICITCD)
EXTRA_PATCHES+=		${PATCHDIR}/xpatch-implicitcd
.endif

.if !defined(WITHOUT_COLONBREAKSWORDS)
EXTRA_PATCHES+=		${PATCHDIR}/xpatch-colonbreakswords
.endif

MAN1=			bash.1 bashbug.1
INFO=			bash

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=		yes
USE_BISON=		build

.if !defined(NOPORTDOCS)
.if !defined(WITH_INCLUDED_FAQ)
DISTFILES+=		FAQ:faq
.endif
PORTDOCS=		FAQ INTRO CHANGES COMPAT NEWS POSIX RBASH
.endif

CONFIGURE_ARGS=		--without-bash-malloc \
			--disable-rpath \
			--enable-disabled-builtins

.if defined(WITH_STATIC_BASH) || defined(NO_DYNAMICROOT) || (defined(NOSHARED) && ${NOSHARED:L} != "no")
.if !defined(WITHOUT_NLS)
WITHOUT_NLS=yes
.endif
CONFIGURE_ARGS+=	--enable-static-link
PKGNAMESUFFIX=	-static
CONFLICTS+=	bash-[0-9]* bash3-[0-9]* bash3-static-[0-9]*
.else
CONFIGURE_ARGS+=	--enable-static-link=no
CONFLICTS+=	bash-static-[0-9]* bash3-[0-9]* bash3-static-[0-9]*
.endif

.if defined(WITHOUT_HELP)
CONFIGURE_ARGS+=	--disable-help-builtin
PLIST_SUB+=		HELP="@comment "
.elif defined(WITH_INTEGRATED_HELPFILES)
PLIST_SUB+=		HELP="@comment "
.else
CONFIGURE_ARGS+=	--enable-separate-helpfiles
PLIST_SUB+=		HELP=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_ICONV=		yes
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

CPPFLAGS+=		${PTHREAD_CFLAGS} \
			-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ENV=		YACC="bison -y"

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/bash.1
.if defined(WITH_SYSLOG)
	@${REINPLACE_CMD} \
	    -e "s|/\*.*#define SYSLOG_HISTORY .*\*/|#define SYSLOG_HISTORY|g" \
	    ${WRKSRC}/config-top.h
.endif
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e "s|@LIBICONV@||g" ${WRKSRC}/Makefile.in
.endif

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|"
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e "s|#define HAVE_ICONV 1|#undef HAVE_ICONV|g" ${WRKSRC}/config.h
.endif

pre-build:
	@${ECHO_CMD} $$((${PORTREVISION}-1)) > ${WRKSRC}/.build

pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@cd ${PREFIX}/bin ; ${LN} -sf bash rbash
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.if !defined(WITH_INCLUDED_FAQ)
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/FAQ \
		${WRKSRC}/doc/INTRO ${DOCSDIR}
.else
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ \
		${WRKSRC}/doc/INTRO ${DOCSDIR}
.endif
	@for d in ${PORTDOCS:NFAQ:NINTRO}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${DOCSDIR}; \
	done
.endif
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

regress: build
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test

ckp:
	${MAKE} -DPATCH_DEBUG clean patch

cklatest:
	@${ECHO} -n "Currently at: "
	@${MAKE} -V PATCHLEVEL
	-ncftpls \
	    ftp://ftp.cwru.edu/pub/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/\.[0-9a-z]*$//}-patches/ \
		| fgrep -v .sig | ${TAIL}

.include <bsd.port.post.mk>
