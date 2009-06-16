# Ports collection makefile for:  pear-Services_Yadis
# Date created:			  21 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Services_Yadis
PORTVERSION=	0.2.3
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Implementation of the Yadis Specification 1.0 protocol for PHP5

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	simplexml
CATEGORY=	Services
FILES=		Yadis.php Yadis/Xri.php Yadis/Xrds.php Yadis/Service.php \
		Yadis/Exception.php Yadis/Xrds/Namespace.php \
		Yadis/Xrds/Service.php

TESTS=		test.php

post-extract:
	${MKDIR} ${WRKSRC}/tests
	${MV} ${WRKSRC}/test.php ${WRKSRC}/tests

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
