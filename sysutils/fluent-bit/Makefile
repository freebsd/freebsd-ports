# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fluent-bit
DISTVERSION=	1.3.2
CATEGORIES=	sysutils
MASTER_SITES=   https://fluentbit.io/releases/${DISTVERSION:R}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Fast and lightweight data forwarder

LICENSE=	APACHE20

BROKEN_mips=		fails to build: conflicting types for 'restrict'
BROKEN_mips64=		fails to build: conflicting types for 'restrict'
BROKEN_powerpc64=	fails to build: cast from pointer to integer of different size

USES=		cmake:noninja gmake bison

USE_RC_SUBR=	${PORTNAME}

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/parsers.conf ${STAGEDIR}${ETCDIR}/parsers.conf.sample

.include <bsd.port.mk>
