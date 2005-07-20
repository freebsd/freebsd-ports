# New ports collection makefile for:    bash3
# Date created:				30 Jul 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		bash
PORTVERSION=		3.0.${PATCHLEVEL}
PORTREVISION=		1
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GNU:S/$/:bash/} \
			http://cnswww.cns.cwru.edu/~chet/%SUBDIR%/:faq \
			ftp://ftp.cwru.edu/pub/%SUBDIR%/:bash,faq
MASTER_SITE_SUBDIR=	${PORTNAME}/:bash,faq
DISTNAME=		${PORTNAME}-${PORTVERSION:R}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}:bash
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=		ftp://ftp.cwru.edu/pub/%SUBDIR%/:bash
PATCH_SITE_SUBDIR=	${PORTNAME}/${DISTNAME}-patches/:bash
.for patch in		01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
PATCHFILES+=		${PORTNAME}${PORTVERSION:R:S/.//g}-0${patch}:bash
PATCHLEVEL=		${patch}
.endfor

MAINTAINER=		obrien@FreeBSD.org
COMMENT=		The GNU Project's Bourne Again SHell

IGNOREFILES=		FAQ
CONFLICTS=		bash-[0-24-9].*

.if !defined(WITHOUT_IMPLICITCD)
EXTRA_PATCHES+=		${PATCHDIR}/xpatch-implicitcd
.endif

.if !defined(WITHOUT_COLONBREAKSWORDS)
EXTRA_PATCHES+=		${PATCHDIR}/xpatch-colonbreakswords
.endif

MAN1=			bash.1 bashbug.1
INFO=			bash

USE_REINPLACE=		yes
GNU_CONFIGURE=		yes

.if !defined(NOPORTDOCS)
.if !defined(WITH_INCLUDED_FAQ)
DISTFILES+=		FAQ:faq
.endif
PORTDOCS=		FAQ INTRO CHANGES COMPAT NEWS POSIX RBASH
.endif

CONFIGURE_ARGS=		--without-bash-malloc \
			--disable-rpath \
			--enable-disabled-builtins

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
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CPPFLAGS+=		${PTHREAD_CFLAGS} \
			-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600006
CONFIGURE_ARGS+=	--with-installed-readline
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/bash.1

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|"

pre-build:
	@${ECHO_CMD} $$((${PORTREVISION}-1)) > ${WRKSRC}/.build

pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DESTDIR}${DOCSDIR}
.if !defined(WITH_INCLUDED_FAQ)
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/FAQ \
		${WRKSRC}/doc/INTRO ${DESTDIR}${DOCSDIR}
.else
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ \
		${WRKSRC}/doc/INTRO ${DESTDIR}${DOCSDIR}
.endif
	@for d in ${PORTDOCS:NFAQ:NINTRO}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${DESTDIR}${DOCSDIR}; \
	done
.endif
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
