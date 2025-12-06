PORTNAME=	gsl
PORTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The GNU Scientific Library - mathematical libs
WWW=		https://www.gnu.org/software/gsl

LICENSE=	GPLv3

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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
