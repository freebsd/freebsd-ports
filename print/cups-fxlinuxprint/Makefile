PORTNAME=	fxlinuxprint
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://download.fujixerox.co.jp/pub/exe/apeosport/c4300series/
PKGNAMEPREFIX=	cups-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Fuji Xerox Printer Driver

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups

USES=		dos2unix ghostscript:run localbase:ldflags
DOS2UNIX_FILES=	fxlinuxprint.ppd
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
