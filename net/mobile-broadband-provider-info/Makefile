PORTNAME=	mobile-broadband-provider-info
PORTVERSION=	20251101
CATEGORIES=	net gnome

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Service mobile broadband provider database
WWW=		https://wiki.gnome.org/Projects/NetworkManager/MobileBroadband/ServiceProviders

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson

USE_GITHUB=	yes
GH_ACCOUNT=	gnome

USE_GNOME=	libxslt
NO_ARCH=	yes

PLIST_FILES=	${DATADIR}/apns-conf.xml \
		${DATADIR}/serviceproviders.2.dtd \
		${DATADIR}/serviceproviders.xml \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>
