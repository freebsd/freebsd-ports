# New ports collection makefile for:	 asWedit
# Date created:		25 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	asWedit
PORTVERSION=	4.0.1
CATEGORIES=	www editors linux
MASTER_SITES=	http://www.advasoft.com/asWedit/ \
		ftp://sunsite.doc.ic.ac.uk/packages/www/asWedit/ \
		ftp://sunsite.auc.dk/pub/infosystems/www/asWedit/ \
		ftp://sunsite.icm.edu.pl/pub/www/asWedit/
DISTNAME=	asWedit-4.0-i386.linux

MAINTAINER=	brett@peloton.runet.edu

RESTRICTED=	"Commercial software"
NO_BUILD=	yes
NO_PACKAGE=	${RESTRICTED}

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
WRKSRC=		${WRKDIR}/asWedit-4.0.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asWedit ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asWedit.hlp ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/share/doc/asWedit
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/asWedit

post-install:
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/share/doc/asWedit/LICENSE."

.include <bsd.port.mk>
