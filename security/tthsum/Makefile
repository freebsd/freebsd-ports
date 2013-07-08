# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	tthsum
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://tthsum.devs.nu/pkg/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line utility for generating and checking TTH message digests

LICENSE=	GPLv3

CONFLICTS=	microdc2-[0-9]*

USES=		gmake
MANCOMPRESSED=	yes

MAKE_JOBS_SAFE=	yes

MAN1=		tthsum.1
PLIST_FILES=	bin/tthsum

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} test runtest

.include <bsd.port.mk>
