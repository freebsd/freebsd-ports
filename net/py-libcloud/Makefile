# Ports collection makefile for:	py-libcloud
# Date created:				2010-12-16
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcloud
PORTVERSION=	0.4.2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	incubator/libcloud
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	apache-${PORTNAME}-incubating-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Standard client library for many popular cloud providers

LICENSE=	ASL

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-incubating-${PORTVERSION}

PYDISTUTILS_EGGINFO=	apache_${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg-info

.include <bsd.port.mk>
