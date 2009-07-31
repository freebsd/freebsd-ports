# New ports collection makefile for:	galculator
# Date created:			2003-06-26
# Whom:				Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galculator
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GTK2-based scientific calculator

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

MAN1=		galculator.1

.include <bsd.port.mk>
