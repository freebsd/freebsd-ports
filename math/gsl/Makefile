# Created by: Andrew L. Neporada <andrew@chg.ru>
# $FreeBSD$

PORTNAME=	gsl
PORTVERSION=	2.6
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	The GNU Scientific Library - mathematical libs

LICENSE=	GPLv3

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		gsl-ref

#prevent regression test coredumps from causing failures on the
#package-building cluster:
.ifndef(MAINTAINER_MODE)
CORELIMIT?=	/usr/bin/limits -Sc 0
.endif

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CORELIMIT} ${MAKE_CMD} \
	${MAKE_ARGS} check

.include <bsd.port.mk>
