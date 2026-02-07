PORTNAME=	kannel-sqlbox
PORTVERSION=	1.0.1
PORTREVISION=	10
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
# Co-maintainer: Alberto Mijares <amijaresp@gmail.com> (PR/173889)
COMMENT=	Add-on module for www/kannel (svn rev.55)
WWW=		https://redmine.kannel.org/projects/kannel-sq-lbox

LICENSE=	The_Kannel_Software_License
LICENSE_NAME=	The Kannel Software License, Version 1.0
LICENSE_FILE=	${WRKSRC}/KannelLICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/kannel/gw-config.h:www/kannel
LIB_DEPENDS=	libpcreposix.so:devel/pcre
RUN_DEPENDS=	${LOCALBASE}/sbin/bearerbox:www/kannel

USES=		gmake gnome iconv ssl
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	dbaio
USE_GNOME=	libxml2
USE_RC_SUBR=	kannel_sqlbox

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFAULT=	SQLITE3
OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL SQLITE3

MYSQL_USES=	mysql
MYSQL_VARS=	IGNORE_WITH_MYSQL=80
PGSQL_USES=	pgsql
SQLITE3_USES=	sqlite:3

post-install:
	${INSTALL_DATA} ${WRKSRC}/example/sqlbox.conf.example \
	${STAGEDIR}${PREFIX}/etc/sqlbox.conf.sample
.include <bsd.port.mk>
