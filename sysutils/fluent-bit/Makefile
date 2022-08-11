PORTNAME=	fluent-bit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.6
CATEGORIES=	sysutils

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Fast and lightweight data forwarder

LICENSE=	APACHE20

BROKEN_mips=		fails to build: conflicting types for 'restrict'
BROKEN_mips64=		fails to build: conflicting types for 'restrict'

USE_GITHUB=	yes
GH_ACCOUNT=	fluent

USES=		cmake:noninja gmake bison

OPTIONS_DEFINE=		SSL PGSQL
OPTIONS_DEFAULT=	SSL

LIB_DEPENDS=		libyaml.so:textproc/libyaml
LDFLAGS+=		-lexecinfo -L${LOCALBASE}/lib
CMAKE_ARGS=		-DFLB_DEBUG=Off -DFLB_TRACE=Off
CFLAGS+=		-I${LOCALBASE}/include

SSL_USES=		ssl
SSL_CMAKE_ON=		-DFLB_TLS=On
SSL_CMAKE_OFF=		-DFLB_TLS=Off

EXAMPLES_CMAKE_ON=	-DFLB_EXAMPLES=On
EXAMPLES_CMAKE_OFF=	-DFLB_EXAMPLES=Off

PGSQL_USES=		pgsql
PGSQL_CMAKE_ON=		-DFLB_OUT_PGSQL=On
PGSQL_CMAKE_OFF=	-DFLB_OUT_PGSQL=Off

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*} || ${ARCH:Mriscv64*}
CMAKE_ARGS+=	-DFLB_LUAJIT:BOOL=OFF
.elif ${ARCH} == powerpc
LDFLAGS+=	-latomic
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c11
.endif

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/parsers.conf ${STAGEDIR}${ETCDIR}/parsers.conf.sample

.include <bsd.port.mk>
