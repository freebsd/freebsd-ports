# New ports collection makefile for:	wmdate
# Date created:		1 February 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmdate
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://solfertje.student.utwente.nl/~dalroi/wmdate/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Date app for the WindowMaker dock

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

USE_IMAKE=	yes
USE_XPM=	yes

PLIST_FILES=	bin/wmdate

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO_MSG} "===>   README installed in ${DOCSDIR}"
.endif

.include <bsd.port.mk>
