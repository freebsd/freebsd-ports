# New ports collection makefile for:	managepkg
# Date created:		2005-09-04
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	managepkg
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.cul.de/data/\
		http://home.arcor.de/fehlner/fbsd_ports/\
		http://home.arcor.de/teambushido/fbsd_ports/
EXTRACT_SUFX=	.gz

MAINTAINER=	fehlner@gmx.de
COMMENT=	Script for maintaining ports
# Any ideas for a better comment?

EXTRACT_AFTER_ARGS=	${DISTDIR}/${DISTFILES} > ${WRKSRC}/${PORTNAME}
WRKSRC=	${WRKDIR}
NO_BUILD=	yes
PLIST_FILES=	sbin/managepkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/

.include <bsd.port.mk>
