# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fluent-bit
DISTVERSION=	0.10.1
CATEGORIES=	sysutils
MASTER_SITES=   http://fluentbit.io/releases/${DISTVERSION:R}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Fast and lightweight data forwarder

LICENSE=	APACHE20

BROKEN_aarch64=		fails to build: error: unknown type name thread_local
BROKEN_armv6=		fails to configure: failure in cmake
BROKEN_mips=		fails to build: conflicting types for 'restrict'
BROKEN_mips64=		fails to build: conflicting types for 'restrict'
BROKEN_powerpc64=	fails to build: cast from pointer to integer of different size

USES=		cmake

post-stage:
		@${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.mk>
