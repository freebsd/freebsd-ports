# Created by: Pietro Cerutti <gahr@gahr.ch>
# $FreeBSD$

PORTNAME=	scew
PORTVERSION=	1.1.7
CATEGORIES=	textproc
MASTER_SITES=	SAVANNAH/${PORTNAME}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple C Expat Wrapper

LICENSE=	LGPL21

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SCEW_EXAMPLES=	print stream write

post-install:
.for ex in ${SCEW_EXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${PORTNAME}_${ex}/${PORTNAME}_${ex} ${STAGEDIR}${PREFIX}/bin
.endfor

.ifdef MAINTAINER_MODE
LIB_DEPENDS+=	libcheck.so:${PORTSDIR}/devel/libcheck
regression-test: build
	cd ${WRKSRC}/tests && ${GMAKE} check
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
