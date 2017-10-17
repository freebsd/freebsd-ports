# $FreeBSD$

PORTNAME=	kannel-sqlbox
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	dbaio@FreeBSD.org
# Co-maintainer: Alberto Mijares <amijaresp@gmail.com> (PR/173889)
COMMENT=	Add-on module for www/kannel (svn rev.55)

LICENSE=	The_Kannel_Software_License
LICENSE_NAME=	The Kannel Software License, Version 1.0
LICENSE_FILE=	${WRKSRC}/KannelLICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/kannel/gw-config.h:www/kannel
RUN_DEPENDS=	${LOCALBASE}/sbin/bearerbox:www/kannel
LIB_DEPENDS=	libpcreposix.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	dbaio

USES=	gmake iconv ssl
USE_GCC=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2

OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE3
OPTIONS_DEFAULT=	MYSQL

MYSQL_USES=	mysql

PGSQL_USES=	pgsql

SQLITE3_USES=	sqlite:3

USE_RC_SUBR=	kannel_sqlbox
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/sqlbox.conf.example \
	${STAGEDIR}${PREFIX}/etc/sqlbox.conf.sample
.include <bsd.port.mk>
