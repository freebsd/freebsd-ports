# New ports collection makefile for: 	gtklp
# Date created:		22 Oct 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gtklp
PORTVERSION=	0.9p
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtklp
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gtk interface to cups

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtklp.1 gtklpq.1

.include <bsd.port.mk>
