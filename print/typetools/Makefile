# ex:ts=8
# Ports collection makefile for:	typetools
# Date created:			Dec 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	typetools
PORTVERSION=	1.80
CATEGORIES=	print
MASTER_SITES=	http://www.lcdf.org/type/
DISTNAME=	lcdf-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for manipulating fonts

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX

GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/lcdf-${PORTNAME}

MAN1=	cfftot1.1 mmafm.1 mmpfb.1 otfinfo.1 otftotfm.1 t1lint.1 t1testpage.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Configure fails"
.endif

.include <bsd.port.post.mk>
