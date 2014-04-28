# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/mail/evolution-ews/Makefile 19239 2014-03-23 08:19:17Z kwm $

PORTNAME=	evolution-ews
PORTVERSION=	3.12.0
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange Web Services

BUILD_DEPENDS=	evolution>=3.0.0:${PORTSDIR}/mail/evolution
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libmspack.so:${PORTSDIR}/archivers/libmspack \
		libical.so:${PORTSDIR}/devel/libical
RUN_DEPENDS=	evolution>=3.0.0:${PORTSDIR}/mail/evolution

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_SQLITE=	3
USE_BDB=	5
USE_OPENLDAP=	yes
USE_GNOME=	gnomeprefix intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

VERSION=	3.12
PLIST_SUB=	VERSION=${VERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server/lib*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server/*/lib*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution/${VERSION}/modules/module-*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/evolution-data-server/registry-modules/*.so

.include <bsd.port.mk>
