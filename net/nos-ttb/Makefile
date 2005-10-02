#
# New ports collection makefile for:	nos-ttb
# Date created:				6 May 2005
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	nos-ttb
PORTVERSION=	0.9.3
CATEGORIES=	net
MASTER_SITES=	http://www.djcbsoftware.nl/code/ttb/
DISTNAME=	ttb-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	NOS teletekst browser

NO_BUILD=	yes
USE_PYTHON=	yes

do-install:
	${MKDIR} ${PREFIX}/share/ttb
	${INSTALL_SCRIPT} ${WRKSRC}/src/ttb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/glade/ttb.glade ${PREFIX}/share/ttb
	${INSTALL_DATA} ${WRKSRC}/images/ttb.png ${PREFIX}/share/ttb

.include <bsd.port.mk>
