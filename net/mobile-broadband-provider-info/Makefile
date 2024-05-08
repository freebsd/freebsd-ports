PORTNAME=	mobile-broadband-provider-info
PORTVERSION=	20240407
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Service mobile broadband provider database
WWW=		https://wiki.gnome.org/Projects/NetworkManager/MobileBroadband/ServiceProviders

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson tar:xz

USE_GNOME=	libxslt
NO_ARCH=	yes

PLIST_FILES=	${DATADIR}/apns-conf.xml \
		${DATADIR}/serviceproviders.2.dtd \
		${DATADIR}/serviceproviders.xml \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>
