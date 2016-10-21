# $FreeBSD$

PORTNAME=	mobile-broadband-provider-info
PORTVERSION=	20151214
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Service mobile broadband provider database

LICENSE=	PD

USES=		autoreconf pathfix tar:xz
GNU_CONFIGURE=	yes

PLIST_FILES=	${DATADIR}/serviceproviders.2.dtd \
		${DATADIR}/serviceproviders.xml \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>
