# $FreeBSD$

PORTNAME=	owncloud
PORTVERSION=	5.0.12
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3

BUILD_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PHP=	ctype curl dom fileinfo filter gd hash iconv json ldap \
		mbstring mysql openssl pdo pdo_mysql pdo_pgsql pdo_sqlite \
		session simplexml sqlite3 xml xmlreader xsl wddx zip zlib
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5

WWWDOCROOT?=	www

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	OWNCLOUDDIR=${OWNCLOUDDIR}
OWNCLOUDDIR=	${WWWDOCROOT}/${PORTNAME}

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${OWNCLOUDDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${OWNCLOUDDIR}

.include <bsd.port.mk>
