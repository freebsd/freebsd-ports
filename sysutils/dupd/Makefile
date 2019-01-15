# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	dupd
PORTVERSION=	1.7
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	File duplicate detection CLI utility

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS+=	bash:shells/bash

USES=		gmake localbase perl5 sqlite:3 ssl
USE_PERL5=	test

ALL_TARGET=	dupd
TEST_TARGET=	test

USE_GITHUB=	yes
GH_ACCOUNT=	jvirkki

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_MAKE_ARGS=	CFLAGS="${CFLAGS:S/O2/O3/g}"

# This gets rid of extra optimization caused by opt?
post-extract:
	${REINPLACE_CMD} -e '/OPT?=/d' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs ; ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
