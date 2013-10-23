# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	tthsum
PORTVERSION=	1.3.2
CATEGORIES=	security
MASTER_SITES=	http://tthsum.devs.nu/pkg/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line utility for generating and checking TTH message digests

LICENSE=	GPLv3

CONFLICTS=	microdc2-[0-9]*

USES=		gmake

PLIST_FILES=	bin/tthsum man/man1/tthsum.1.gz

MAKE_ENV+=	STAGEDIR=${STAGEDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} test runtest

.include <bsd.port.mk>
