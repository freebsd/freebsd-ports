# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GiNaC
PORTVERSION=	1.7.10
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	C++ library for symbolic mathematical calculations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcln.so:math/cln

USES=		gmake libtool makeinfo pathfix pkgconfig python:build \
		tar:bzip2 compiler:c++11-lib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		ginac ginac-examples

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/configure
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} -e 's|unsigned|size_t|g' \
		${WRKSRC}/ginac/parser/parser.cpp
.endif
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' \
		${WRKSRC}/scripts/yaptu.py \
		${WRKSRC}/scripts/fixupind.py \
		${WRKSRC}/ginac/function.py \
		${WRKSRC}/ginsh/ginsh_fcn_help.py \
		${WRKSRC}/ginsh/ginsh_op_help.py

.include <bsd.port.post.mk>
