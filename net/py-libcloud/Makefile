# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcloud
PORTVERSION=	1.0.0
CATEGORIES=	net python
MASTER_SITES=	APACHE/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Standard client library for many popular cloud providers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

USES=		cpe python tar:bzip2
USE_PYTHON=	distutils autoplist
CPE_VENDOR=	apache

post-extract:
	@${MV} ${WRKSRC}/libcloud/test ${WRKSRC}/test # no need to install tests
	@${FIND} ${WRKSRC} -name "*.rej" -delete

.include <bsd.port.mk>
