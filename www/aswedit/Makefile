# New ports collection makefile for:	 asWedit
# Date created:		25 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	asWedit
PORTVERSION=	4.0.1
PORTREVISION=	2
CATEGORIES=	www editors linux
MASTER_SITES=	ftp://sunsite.icm.edu.pl/pub/www/asWedit/
DISTNAME=	asWedit-4.0-i386.linux

MAINTAINER=	brett@peloton.runet.edu
COMMENT=	An easy to use HTML and text editor

RESTRICTED=	"Commercial software"

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/asWedit-4.0.1

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/asWedit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asWedit ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asWedit.hlp ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/share/doc/asWedit
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/asWedit

post-install:
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/share/doc/asWedit/LICENSE."

.include <bsd.port.mk>
