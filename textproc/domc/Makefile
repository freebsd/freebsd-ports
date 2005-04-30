# ex:ts=8
# New ports collection makefile for:	domc
# Date created:			Oct 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	domc
PORTVERSION=	0.8.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.ioplex.com/~miallen/domc/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A light weight implementation of the DOM in ANSI C

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		mba.1:${PORTSDIR}/devel/libmba

MAN3=		DOM_CharacterData.3m DOM_Document.3m DOM_Element.3m \
		DOM_Implementation.3m DOM_NamedNodeMap.3m DOM_Node.3m \
		DOM_NodeList.3m DOM_Text.3m
MANCOMPRESSED=	yes

SHLIB_MAJOR=	0

USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	SHLIB_MAJOR="${SHLIB_MAJOR}" INSTDIR=${PREFIX} LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
IGNORE=		requires wchar functions to use the produced library
.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

.include <bsd.port.post.mk>
