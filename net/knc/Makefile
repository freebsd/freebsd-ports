PORTNAME=	knc
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://oskt.secure-endpoints.com/downloads/

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Kerberised NetCat
WWW=		https://oskt.secure-endpoints.com/knc.html

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi

USES=		cpe libtool
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPE_VENDOR=	secure-endpoints
CPE_PRODUCT=	kerberised_netcat

PLIST_FILES=	bin/knc \
		share/man/man1/knc.1.gz

.include <bsd.port.mk>
