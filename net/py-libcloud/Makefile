# Ports collection makefile for:	py-libcloud
# Date created:				2010-12-16
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcloud
PORTVERSION=	0.8.0
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Standard client library for many popular cloud providers

LICENSE=	AL2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_BZIP2=	yes

PYDISTUTILS_EGGINFO=	apache_${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info

.include <bsd.port.mk>
