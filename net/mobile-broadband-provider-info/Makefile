# $FreeBSD$

PORTNAME=	mobile-broadband-provider-info
PORTVERSION=	20190618
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Service mobile broadband provider database

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake gnome pathfix tar:xz

USE_GNOME=	libxslt
GNU_CONFIGURE=	yes

PLIST_FILES=	${DATADIR}/apns-conf.xml \
		${DATADIR}/serviceproviders.2.dtd \
		${DATADIR}/serviceproviders.xml \
		libdata/pkgconfig/${PORTNAME}.pc

.include <bsd.port.mk>
