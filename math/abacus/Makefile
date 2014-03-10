# Created by: gahr
# $FreeBSD$

PORTNAME=	abacus
DISTVERSION=	3.2betaU1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.informatik.uni-koeln.de/abacus/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Branch-And-CUt System

LICENSE=	GPLv2

LIB_DEPENDS=	libClp.so:${PORTSDIR}/math/coinmp

USE_GCC=	yes
USES=		gmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes
ALL_TARGET=	abacus

WRKSRC=		${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e '\
	    s|%%LOCALBASE%%|${LOCALBASE}|g; \
	    s|%%CXX%%|${CXX}|g; \
	    s|%%PERL5%%|${PERL5}|g' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/linux20-gcc44/libabacus-osi.a ${STAGEDIR}${PREFIX}/lib/libabacus-osi.a
	${INSTALL_DATA} ${WRKSRC}/lib/linux20-gcc44/libabacus-osi.so ${STAGEDIR}${PREFIX}/lib/libabacus-osi.so.1
	${LN} -sf libabacus-osi.so.1 ${STAGEDIR}${PREFIX}/lib/libabacus-osi.so
	cd ${WRKSRC}/Include && ${COPYTREE_SHARE} abacus ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
