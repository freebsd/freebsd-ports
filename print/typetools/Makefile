# ex:ts=8
# Ports collection makefile for:	typetools
# Date created:			Dec 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	typetools
PORTVERSION=	2.30
CATEGORIES=	print
MASTER_SITES=	http://www.lcdf.org/type/
DISTNAME=	lcdf-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for manipulating fonts

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX-base

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-kpathsea=${LOCALBASE}

MAN1=		cfftot1.1 mmafm.1 mmpfb.1 otfinfo.1 otftotfm.1 t1dotlessj.1 \
		t1lint.1 t1reencode.1 t1testpage.1

DATADIR=	${PREFIX}/share/lcdf-${PORTNAME}

.include <bsd.port.mk>
