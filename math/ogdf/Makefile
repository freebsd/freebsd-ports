# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ogdf
PORTVERSION=	2015.05
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ogdf.net/lib/exe/fetch.php/tech:
DISTNAME=	${PORTNAME}.v${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	C++ class library for the automatic layout of diagrams

LICENSE=		GPLv2 GPLv3
LICENSE_COMB=		dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE_GPL_v2.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE_GPL_v3.txt

USES=			compiler:features gmake python:2.7,build zip
USE_LDCONFIG=		yes
LDFLAGS+=		-L${LOCALBASE}/lib

FETCH_BEFORE_ARGS=	-o ${PORTNAME}.v${PORTVERSION}.zip
WRKSRC=			${WRKDIR}/${PORTNAME:tu}

OPTIONS_DEFINE=		COIN
OPTIONS_DEFAULT=	COIN
OPTIONS_SUB=		yes

COIN_DESC=		Build with COIN solvers
COIN_USE=		coin=true
COIN_CONFLICTS_INSTALL=	CoinMP

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mc++11}
STDCPP11=		-std=c++11
.endif

post-patch:
	@${REINPLACE_CMD} -e '\
	    s|%%CXX%%|${CXX}|g; \
	    s|%%CXXFLAGS%%|${CXXFLAGS}|g; \
	    s|%%LOCALBASE%%|${LOCALBASE}|g; \
	    s|%%USE_COIN%%|${USE_COIN}|g' \
		${WRKSRC}/makeMakefile.config

	@${REINPLACE_CMD} -e '\
	    s|%%STDCPP11%%|${STDCPP11}|g' \
		${WRKSRC}/makeMakefile.py

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} makeMakefile.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libOGDF.so
.if ${PORT_OPTIONS:MCOIN}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libCOIN.so
.endif

.include <bsd.port.post.mk>
