# New ports collection makefile for:    bash3
# Date created:				30 Jul 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		bash
PORTVERSION=		3.0
PORTREVISION=		2
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GNU} \
			ftp://ftp.cwru.edu/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	bash

MAINTAINER=		eik@FreeBSD.org
COMMENT=		The GNU Project's Bourne Again SHell

CONFLICTS=		bash-[0-24-9].*
LATEST_LINK=		${PKGNAMEPREFIX}bash3${PKGNAMESUFFIX}

USE_REINPLACE=		yes

MAN1=			bash.1 bashbug.1
INFO=			bash

USE_REINPLACE=		yes
GNU_CONFIGURE=		yes

.if !defined(NOPORTDOCS)
PORTDOCS=		CHANGES COMPAT NEWS POSIX RBASH
.endif

CONFIGURE_ARGS=		--without-bash-malloc

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

post-patch:
	@${REINPLACE_CMD} -e "s| /bin| ${PREFIX}/bin|g" ${WRKSRC}/doc/bash.1

pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for d in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${d} ${DESTDIR}${DOCSDIR}; \
	done
.endif
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL; \

.include <bsd.port.mk>
