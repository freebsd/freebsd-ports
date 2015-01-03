# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgitop
PORTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=source/u/${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	uWSGI top-like app

USES=		python
USE_PYTHON=	distutils

post-install:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
