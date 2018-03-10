# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plplot
PORTVERSION=	${RELEASE}
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source
PKGNAMESUFFIX=	-ada

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada bindings for PLplot

LICENSE=	LGPL3

LIB_DEPENDS=	libplplot.so:math/plplot

USES=		ada

DISTINFO_FILE=	${.CURDIR}/../plplot/distinfo
RELEASE!=	awk '/SHA/ {split($$2,a,"."); print substr(a[1], 9) "." a[2] "." a[3];}' ${DISTINFO_FILE}
BUILD_WRKSRC=	${WRKSRC}/bindings
INSTALL_WRKSRC=	${WRKSRC}/bindings

post-extract:
	${CP} ${FILESDIR}/build_plplot.gpr ${FILESDIR}/Makefile \
		${BUILD_WRKSRC}
	${CAT} ${FILESDIR}/plplot.gpr.in | \
		${SED} -e "s|@PREFIX@|${PREFIX}|g" > ${BUILD_WRKSRC}/plplot.gpr

.include <bsd.port.mk>
