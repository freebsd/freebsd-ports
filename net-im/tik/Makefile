# New ports collection makefile for:	tik
# Version required:	0.52
# Date created:		13 January 1999
# Whom:			Eugene M. Kim <astralblue@usa.net>
#
# $Id: Makefile,v 1.1.1.1 1998/12/24 15:28:00 flathill Exp $
#

DISTNAME=	tik-0.52
CATEGORIES=	net tk80
MASTER_SITES=	http://www.aim.aol.com/tik/

MAINTAINER=	astralblue@usa.net

RUN_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80 \
		wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/tik

NO_BUILD=	yes
PLIST_SUB=	DISTNAME=${DISTNAME}

do-install:
	cd ${WRKSRC} ; \
	find -d media packages *.tcl -print0 | \
	    cpio -dump0 --owner=root:wheel ${PREFIX}/lib/${DISTNAME} ; \
	${MKDIR} ${PREFIX}/share/examples/${DISTNAME} ; \
	${INSTALL_DATA} example.* ${PREFIX}/share/examples/${DISTNAME}/ ; \
	${INSTALL_SCRIPT} ${FILESDIR}/tik ${PREFIX}/bin/${DISTNAME} ; \
	ln -sf ${DISTNAME} ${PREFIX}/bin/tik
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} ; \
	${MKDIR} ${PREFIX}/share/doc/${DISTNAME} ; \
	${INSTALL_DATA} PROTOCOL CHANGES README LICENSE ${PREFIX}/share/doc/${DISTNAME}/
.endif

.include <bsd.port.mk>
