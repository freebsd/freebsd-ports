# Created by: jmz
# $FreeBSD$

PORTNAME=	calc
PORTVERSION=	2.12.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Interactive CLI arbitrary-precision calculator

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL

USES=		gmake tar:bzip2 readline
USE_GITHUB=	yes
GH_ACCOUNT=	lcn2

MAKE_JOBS_UNSAFE=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

MAKEFILE=	Makefile.ship
MAKE_ARGS=	DATADIR="${DATADIR}"
TEST_TARGET=	check

OPTIONS_DEFINE=	FULL HELP
OPTIONS_DEFAULT=FULL HELP
OPTIONS_SUB=	yes
FULL_DESC=	Install all funcs/scripts/headers (OFF: just basic calculator)
HELP_DESC=	Install calc help files

post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/calc lib/lib*.so

.include <bsd.port.mk>
