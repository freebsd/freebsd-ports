# New ports collection makefile for:	extipl
# Date created:		8 January 2001
# Whom:			KIMURA Takamichi <takamiti@tsden.org>
#
# $FreeBSD$
#

PORTNAME=	extipl
PORTVERSION=	5.01
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.tsden.org/pub/extipl/PC-Unix/

MAINTAINER=	takamiti@tsden.org

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAN8=		extipl.8
MANCOMPRESSED=	yes

post-patch:
	cd ${WRKSRC}; \
	${PERL} -pi -e 's/^(CC)\t=/$$1?=/;' \
		-e 's/(DIR)[\t]*[?]=/$$1=/;' Makefile

.include <bsd.port.mk>
