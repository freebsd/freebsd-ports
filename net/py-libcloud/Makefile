# Ports collection makefile for:	py-libcloud
# Date created:				2010-12-16
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcloud
PORTVERSION=	0.11.1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Standard client library for many popular cloud providers

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PYDISTUTILS_EGGINFO=	apache_${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info

post-extract:
	@${MV} ${WRKSRC}/libcloud/test ${WRKSRC}/test # no need to install tests
	@${FIND} ${WRKSRC} -name "*.rej" -delete

.include <bsd.port.mk>
