# New ports collection makefile for:	rcalc
# Date created:				28 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	rcalc
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	rCalc-${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Symbolic calculator for GNOME

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g'

.include <bsd.port.mk>
