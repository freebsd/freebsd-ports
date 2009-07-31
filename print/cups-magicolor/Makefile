# New ports collection makefile for:	cups-pstoraster
# Date created:		Jul 13 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cups-magicolor
PORTVERSION=	1.5.0
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://printer.konicaminolta.net/drivers/linux/
DISTNAME=	2430DL_sc_linux

MAINTAINER=	frank@exit.com
COMMENT=	CUPS support for the Konica-Minolta Magicolor 2430DL

#BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/print/cups-base:configure
LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		lcms.1:${PORTSDIR}/graphics/lcms
RUN_DEPENDS=	espgs:${PORTSDIR}/print/cups-pstoraster

WRKSRC=		${WRKDIR}/magicolor2430DL-${PORTVERSION}

USE_AUTOTOOLS=	automake:19:env autoconf:262

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
