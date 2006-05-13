# New ports collection makefile for:	cups-pstoraster
# Date created:		Jul 13 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cups-magicolor
PORTVERSION=	1.1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.minolta-qms.com/pub/crc/out_going/other/

MAINTAINER=	frank@exit.com
COMMENT=	CUPS support for the Konica-Minolta Magicolor 2430DL

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/print/cups-base:configure
LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		lcms.1:${PORTSDIR}/graphics/lcms
RUN_DEPENDS=	espgs:${PORTSDIR}/print/cups-pstoraster

DISTNAME=	magicolor2430DL-1.1.0

USE_GMAKE=	yes

do-configure:
	${CP} ${WRKSRC}/../../../cups-base/work/cups-*/config.h ${WRKSRC}

.include <bsd.port.mk>
