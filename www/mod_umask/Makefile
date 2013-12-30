# Created by: Ralf Gebhart <gebhart@secnetix.de>
# $FreeBSD$

PORTNAME=	mod_umask
PORTVERSION=	0.1.0
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_umask/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	gebhart@secnetix.de
COMMENT=	Apache 2.x module to set umask of created files

LICENSE=	APACHE20

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_APACHE=	22+

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	src/${PORTNAME}.c

.include <bsd.port.mk>
