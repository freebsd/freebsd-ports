PORTNAME=	fluent-bit
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.8
CATEGORIES=	sysutils

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Fast and lightweight data forwarder
WWW=		https://fluentbit.io/

LICENSE=	APACHE20

BROKEN_mips=	fails to build: conflicting types for 'restrict'
BROKEN_mips64=	fails to build: conflicting types for 'restrict'

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		bison cmake:noninja compiler:c11 gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	fluent
USE_RC_SUBR=	${PORTNAME}

CMAKE_ARGS=	-DFLB_DEBUG=Off \
		-DFLB_TRACE=Off
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		LUA_FILTER PGSQL SSL
OPTIONS_DEFAULT=	LUA_FILTER PGSQL SSL
LUA_FILTER_DESC=	Support for modifying incoming records using Lua scripts

LUA_FILTER_USES=	luajit:luajit pkgconfig
LUA_FILTER_CMAKE_ON=	-DFLB_FILTER_LUA=On \
			-DFLB_LUAJIT=On \
			-DFLB_PREFER_SYSTEM_LIB_LUAJIT=On
LUA_FILTER_CMAKE_OFF=	-DFLB_LUAJIT=Off

PGSQL_USES=		pgsql
PGSQL_CMAKE_ON=		-DFLB_OUT_PGSQL=On
PGSQL_CMAKE_OFF=	-DFLB_OUT_PGSQL=Off

SSL_USES=	ssl
SSL_CMAKE_ON=	-DFLB_TLS=On
SSL_CMAKE_OFF=	-DFLB_TLS=Off

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/parsers.conf ${STAGEDIR}${ETCDIR}/parsers.conf.sample

do-test-LUA_FILTER-on:
	${STAGEDIR}${PREFIX}/bin/fluent-bit --help 2>/dev/null | grep -w -q lua

.include <bsd.port.mk>
