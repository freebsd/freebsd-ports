# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ogdf
PORTVERSION=	2012.07
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	LOCAL/gahr \
		http://people.freebsd.org/~gahr/distfiles/
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for the automatic layout of diagrams

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE_GPL_v2.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE_GPL_v3.txt

USES=		zip python:build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:tu}

OPTIONS_DEFINE=	COIN ABACUS
COIN_DESC=	Use the Coin Open Solver Interface (Osi)
ABACUS_DESC=	Use the ABACUS branch-and-cut library

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
	@${REINPLACE_CMD} -e '\
	    s|%%CXX%%|${CXX}|g; \
	    s|%%LOCALBASE%%|${LOCALBASE}|g; \
	    s|%%USE_COIN%%|${USE_COIN}|g; \
	    s|%%USE_ABACUS%%|${USE_ABACUS}|g' \
		${WRKSRC}/makeMakefile.config

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} makeMakefile.py

do-install:
	${INSTALL_LIB} ${WRKSRC}/_release/libOGDF.so \
		${STAGEDIR}${PREFIX}/lib/libOGDF.so.1
	${LN} -sf libOGDF.so.1 ${STAGEDIR}${PREFIX}/lib/libOGDF.so
	cd ${WRKSRC} && ${COPYTREE_SHARE} ogdf ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
