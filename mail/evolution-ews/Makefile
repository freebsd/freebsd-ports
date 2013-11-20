# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-ews/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	evolution-ews
PORTVERSION=	3.6.4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange Web Services

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libical.so:${PORTSDIR}/devel/libical
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution

EVO_VER=	3.6.0
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_SQLITE=	3
USE_BDB=	5
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack ltasneededhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

VERSION=	3.6
PLIST_SUB=	VERSION=${VERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server-${VERSION}/libeews-1.2.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server/*/lib*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblzx.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/${VERSION}/modules/module-*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server-${VERSION}/libewsutils.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server/registry-modules/module-ews-backend.so

.include <bsd.port.mk>
