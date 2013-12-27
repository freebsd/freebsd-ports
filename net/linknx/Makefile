# Created by: Björn König <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	linknx
PORTVERSION=	0.0.1.30
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Rule-based event handling in a KNX installation

LICENSE=	GPLv2

LIB_DEPENDS=	libpthsem.so:${PORTSDIR}/devel/pthsem
BUILD_DEPENDS=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone

USES=	gmake
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-I${LOCALBASE}/include -L/${LOCALBASE}/lib"

OPTIONS_DEFINE=	LIBESMTP LIBCURL LIBLUA MYSQL
OPTIONS_DEFAULT=	LIBESMTP
OPTIONS_SUB=
LIBESMTP_DESC=	Install libesmtp for SMTP support
LIBCURL_DESC=	Install libcurl for Clickatell SMS support
LIBLUA_DESC=	Install lilua for scripting
MYSQL_DESC=	Install libmysql for logging & persist

LIBESMTP_CONFIGURE_ENABLE=	smtp
LIBESMTP_LIB_DEPENDS=	libesmtp.so:${PORTSDIR}/mail/libesmtp
LIBCURL_CONFIGURE_WITH=	libcurl
LIBCURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
LIBLUA_CONFIGURE_WITH=	lua
LIBLUA_USE=	lua=yes
LIBLUA_CFLAGS=	-I${LUA_INCDIR}
LIBLUA_LDFLAGS=	-L${LUA_LIBDIR}
MYSQL_CONFIGURE_WITH=	mysql=${LOCALBASE}/bin/mysql_config
MYSQL_USE=	mysql=yes

PORTDOCS=	*

PLIST_FILES=	bin/linknx

USE_RC_SUBR=	${PORTNAME}

post-patch:
	${REINPLACE_CMD} "s/LUAPC=lua/LUAPC=lua-${LUA_VER}/" ${WRKSRC}/configure.ac

.include <bsd.port.mk>
