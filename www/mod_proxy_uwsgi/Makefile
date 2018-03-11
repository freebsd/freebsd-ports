# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgi
PORTVERSION=	2.0.15
CATEGORIES=	www
MASTER_SITES=	http://projects.unbit.it/downloads/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}mod_proxy_

MAINTAINER=	schmidt@ze.tum.de
COMMENT=	Apache proxy module to pass requests to uwsgi

USES=		apache:2.2+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

SRC_FILE=	apache2/mod_proxy_uwsgi.c

MODULENAME=	mod_proxy_uwsgi

.include <bsd.port.mk>
