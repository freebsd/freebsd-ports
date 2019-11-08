# Created by: Domas Mituzas <midom@dammit.lt>
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	1.4.4
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.org/download/${PORTVERSION}/
DISTNAME=	gateway-${PORTVERSION}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	WAP/SMS gateway

LICENSE=	The_Kannel_Software_License
LICENSE_NAME=	The Kannel Software License, Version 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpcre.so:devel/pcre

PORTSCOUT=	skipv:1.5.0

USERS=		kannel
GROUPS=		kannel

USES=		gmake gnome iconv ssl tar:bzip2
USE_GCC=	yes
USE_GNOME=	libxml2
USE_RC_SUBR=	${PORTNAME}_bearerbox ${PORTNAME}_smsbox ${PORTNAME}_wapbox
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pcre=yes --enable-docs=no --with-malloc=native \
		--enable-start-stop-daemon=no

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3
OPTIONS_DEFAULT=	MYSQL

SQLITE3_USES=	sqlite:3
SQLITE3_CONFIGURE_WITH=	sqlite3

MYSQL_USES=	mysql
MYSQL_CONFIGURE_WITH=	mysql

PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	pgsql

post-patch:
	@${RM} ${WRKSRC}/wmlscript/wsgram.y

post-install:
.for filename in wapkannel.conf smskannel.conf
	${INSTALL_DATA} ${WRKSRC}/gw/${filename} \
		${STAGEDIR}${PREFIX}/etc/${filename}.sample
.endfor
.for filename in mtbatch seewbmp wmlsc wmlsdasm decode_emimsg
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${filename}
.endfor
.for filename in bearerbox run_kannel_box smsbox wapbox
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${filename}
.endfor
	@${MKDIR} ${STAGEDIR}/var/log/kannel
	@${MKDIR} ${STAGEDIR}/var/run/kannel

.include <bsd.port.mk>
