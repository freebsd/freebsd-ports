PORTNAME=	mod_umask
PORTVERSION=	0.1.0
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_umask/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	gebhart@secnetix.de
COMMENT=	Apache 2.x module to set umask of created files
WWW=		http://www.outoforder.cc/projects/httpd/mod_umask/

LICENSE=	APACHE20

USES=		apache tar:bzip2

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	src/${PORTNAME}.c

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
