# Created by: gahr
# $FreeBSD$

PORTNAME=	ogdf
PORTVERSION=	2012.07
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~gahr/distfiles/
MASTER_SITE_SUBDIR=	gahr
DISTNAME=	ogdf.v2012.07

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	C++ class library for the automatic layout of diagrams

LICENSE=	GPLv2

OPTIONS_DEFINE=	COIN ABACUS
COIN_DESC=	Use the Coin Open Solver Interface (Osi)
ABACUS_DESC=	Use the ABACUS branch-and-cut library

USES=		zip
USE_LDCONFIG=	yes
USE_PYTHON=	build

WRKSRC=		${WRKDIR}/${PORTNAME:U}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOIN}
LIB_DEPENDS+=	libClp.so:${PORTSDIR}/math/coinmp
USE_COIN=	true
.else
USE_COIN=	false
.endif

.if ${PORT_OPTIONS:MABACUS}
USE_GCC=	yes
LIB_DEPENDS+=	libabacus-osi.so:${PORTSDIR}/math/abacus
USE_ABACUS=	true
USE_COIN=	true
.else
USE_ABACUS=	false
.endif

post-patch:
	${REINPLACE_CMD} -e '\
	    s|%%CXX%%|${CXX}|g; \
	    s|%%LOCALBASE%%|${LOCALBASE}|g; \
	    s|%%USE_COIN%%|${USE_COIN}|g; \
	    s|%%USE_ABACUS%%|${USE_ABACUS}|g' \
	    ${WRKSRC}/makeMakefile.config

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} makeMakefile.py

do-install:
	${INSTALL_DATA} ${WRKSRC}/_release/libOGDF.so ${STAGEDIR}${PREFIX}/lib/libOGDF.so.1
	${LN} -sf libOGDF.so.1 ${STAGEDIR}${PREFIX}/lib/libOGDF.so
	cd ${WRKSRC} && ${COPYTREE_SHARE} ogdf ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
