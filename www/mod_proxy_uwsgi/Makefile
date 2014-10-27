# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_proxy_uwsgi
PORTVERSION=	2.0.8
CATEGORIES=	www
MASTER_SITES=	http://projects.unbit.it/downloads/
DISTNAME=	uwsgi-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Apache proxy module to pass requests to uwsgi

WRKSRC=		${WRKDIR}/uwsgi-${PORTVERSION}
USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

SRC_FILE=	apache2/mod_proxy_uwsgi.c

.include <bsd.port.mk>
