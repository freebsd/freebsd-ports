# New ports collection makefile for: 	gtklp
# Date created:		22 Oct 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gtklp
PORTVERSION=	0.9m
CATEGORIES=	print
MASTER_SITES=	http://www.stud.uni-hannover.de/~sirtobi/gtklp/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	martin.klaffenboeck@gmx.at

LIB_DEPENDS=	cups:${PORTSDIR}/print/cups

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_AUTOCONF_VER=	253

CONFIGURE_ENV=	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lcups"

MAN1=		gtklp.1 gtklpq.1

.include <bsd.port.mk>
