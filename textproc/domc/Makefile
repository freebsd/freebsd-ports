# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	domc
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.ioplex.com/~miallen/domc/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight implementation of the DOM in ANSI C

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libmba.so:${PORTSDIR}/devel/libmba

USES=		gmake
MAKE_ENV=	SHLIB_MAJOR="${SHLIB_MAJOR}" INSTDIR=${PREFIX}
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
SHLIB_MAJOR=	0

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

MAN3=		DOM_CharacterData.3m DOM_Document.3m DOM_Element.3m \
		DOM_Implementation.3m DOM_NamedNodeMap.3m DOM_Node.3m \
		DOM_NodeList.3m DOM_Text.3m
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64-8: duplicate definition of strlen
.endif

.include <bsd.port.post.mk>
