# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgitop
PORTVERSION=	0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=source/u/${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	uWSGI top-like app

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
