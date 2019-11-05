# Created by: jmz
# $FreeBSD$

PORTNAME=	calc
PORTVERSION=	2.12.7.2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Arbitrary precision calculator

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL

USES=		gmake tar:bzip2 readline

USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	lcn2

MAKE_JOBS_UNSAFE=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

MAKEFILE=	Makefile.ship
MAKE_ARGS=	DATADIR="${DATADIR}"
TEST_TARGET=	check

OPTIONS_DEFINE=	FULL HELP
OPTIONS_DEFAULT=FULL HELP
OPTIONS_SUB=	yes
FULL_DESC=	Install all functions, scripts, and headers
HELP_DESC=	Install calc help files

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/calc \
		${STAGEDIR}${PREFIX}/lib/lib*.so

.include <bsd.port.mk>
