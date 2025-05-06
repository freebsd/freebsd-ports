PORTNAME=	libiscsi
DISTVERSION=	1.20.1
CATEGORIES=	net

MAINTAINER=	d8zNeCFG@aon.at
COMMENT=	Client-side library to implement the iSCSI protocol
WWW=		https://github.com/sahlberg/libiscsi

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENCE-GPL-2.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENCE-LGPL-2.1.txt

USES=		autoreconf compiler:c11 gmake libtool pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	sahlberg

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

# 1.20.2 only affects environments defining __APPLE__
PORTSCOUT=	skipv:1.20.2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.11.0.0

.include <bsd.port.mk>
