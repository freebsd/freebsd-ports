# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fluent-bit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Fast and lightweight data forwarder

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	fluent

BROKEN_mips=		fails to build: conflicting types for 'restrict'
BROKEN_mips64=		fails to build: conflicting types for 'restrict'
BROKEN_powerpc64=	fails to build: cast from pointer to integer of different size

USES=		cmake:noninja gmake bison compiler

OPTIONS_DEFINE=		SSL PGSQL
OPTIONS_DEFAULT=	SSL

CMAKE_ARGS=		-DFLB_DEBUG=Off -DFLB_TRACE=Off -DFLB_CORO_STACK_SIZE=24576

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

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-lib_luajit__src__lj_prng.c
.endif

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/parsers.conf ${STAGEDIR}${ETCDIR}/parsers.conf.sample

.include <bsd.port.mk>
