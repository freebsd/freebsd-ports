PORTNAME=	bgpuma
DISTVERSION=	20151209
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Searching BGP update files
WWW=		https://github.com/cmu-sei/bgpuma

LICENSE=	BSD2CLAUSE GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_GPLv3=		${WRKSRC}/COPYING

LIB_DEPENDS=	libbgpdump.so:net/libbgpdump \
		libsilk.so:security/silktools

USES=		autoreconf libtool localbase
USE_GITHUB=	yes
GH_ACCOUNT=	cmu-sei
GH_TAGNAME=	a29b2a7
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/bgpuma share/man/man1/bgpuma.1.gz

.include <bsd.port.mk>
