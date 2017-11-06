# $FreeBSD$

PORTNAME=	gmm++
PORTVERSION=	5.1
CATEGORIES=	math
MASTER_SITES=	http://download.gna.org/getfem/stable/
DISTNAME=	${PORTNAME:S/+//g}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Generic matrix template library

# Note: even though the port's COPYING file mentions gmm++ is licensed under
# the LGPL version 2.1 with the GCC runtime exception,
# <http://download.gna.org/getfem/html/homepage/whatsnew/4.2.html> mentions
# v4.2 is licensed under the LGPL version 3 with the GCC runtime exception, and
# so say the headers which are installed.
LICENSE=	LGPL3

GNU_CONFIGURE=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
