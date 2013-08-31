# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GiNaC
PORTVERSION=	1.6.2
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	A C++ library for symbolic mathematical calculations

LIB_DEPENDS=	cln.6:${PORTSDIR}/math/cln

USE_BZIP2=	yes
USES=		pkgconfig pathfix gmake
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

MAN1=	ginsh.1 viewgar.1
INFO=	ginac ginac-examples

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/configure
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} -e 's|unsigned|size_t|g' ${WRKSRC}/ginac/parser/parser.cpp
.endif

.include <bsd.port.post.mk>
