# New ports collection makefile for:	extipl
# Date created:		8 January 2001
# Whom:			KIMURA Takamichi <takamiti@tsden.org>
#
# $FreeBSD$
#

PORTNAME=	extipl
PORTVERSION=	5.04
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/ \
		http://www.tsden.org/takamiti/extipl/archs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Partition-selectable boot loader for IBM-PC/AT compatibles

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAN8=		extipl.8
MANCOMPRESSED=	yes

post-patch:
	cd ${WRKSRC}; \
	${REINPLACE_CMD} -e 's/^(CC)\t=/$$1?=/;' \
		-e 's/(DIR)[\t]*[?]=/$$1=/;' Makefile

.include <bsd.port.mk>
