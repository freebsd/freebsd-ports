# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgi
PORTVERSION=	2.0.13
CATEGORIES=	www
MASTER_SITES=	http://projects.unbit.it/downloads/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}mod_proxy_

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Apache proxy module to pass requests to uwsgi

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

SRC_FILE=	apache2/mod_proxy_uwsgi.c

.include <bsd.port.mk>
