PORTNAME=	wackamole
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://BSDforge.com/projects/source/net/wackamole/ \
		http://mirrors.omniti.com/wackamole/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Peer-to-peer high availability cluster
WWW=		https://BSDforge.com/projects/net/wackamole/

# same as the net/spread license really
LICENSE=	CNDS_OPEN-SOURCE_LICENSE
LICENSE_NAME=	CNDS Open-Source License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN=		Unfetchable

LIB_DEPENDS=	libspread.so:net/spread

USES=		tar:xz
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	YACC=${YACC}

.include <bsd.port.mk>
