# Created by: Marco Steinbach <coco@executive-computing.de>
# $FreeBSD$

PORTNAME=	redaxo
PORTVERSION=	4.5.1
CATEGORIES=	www
MASTER_SITES=	http://www.redaxo.org/files/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/g}

MAINTAINER=	coco@executive-computing.de
COMMENT=	REDAXO content management system

LICENSE=	GPLv2

NO_BUILD=	yes

SUB_FILES+=	pkg-message pkg-deinstall
USE_PHP=	mysql session xml zlib
USES=		zip:infozip

OPTIONS_DEFINE=	APACHE MYSQLS GD

APACHE_DESC=	Use Apache (2.2) as http server
MYSQLS_DESC=	Use MySQL database server
GD_DESC=	Enable Image Manager extension (requires gd)

OPTIONS_DEFAULT=	APACHE MYSQLS GD

MYSQLS_USE=	MYSQL=server

APACHE_USE=	APACHE_RUN=22

GD_USE=	PHP=gd

do-extract:
	@${INSTALL} -d ${WRKDIR}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DISTFILES} -d ${WRKSRC}

do-install:
	cd ${WRKSRC} && \
	${FIND} . | \
	${CPIO} --quiet -pdm ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
