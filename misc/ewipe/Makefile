# New ports collection makefile for:	ewipe
# Version required:	0.5.0
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.3 1997/10/24 05:57:15 itojun Exp $
#

DISTNAME=	ewipe0.5.0
PKGNAME=	ewipe-0.5.0
CATEGORIES=	japanese x11
MASTER_SITES=	http://al.ei.tuat.ac.jp/~sekisita/ewipe/

MAINTAINER=	itojun@itojun.org

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/ewipe
	${MKDIR} ${PREFIX}/share/doc/ewipe
	${INSTALL_SCRIPT} ${WRKSRC}/ewipe ${PREFIX}/bin
	for i in viewer.tcl edittable.tcl tclIndex; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/lib/ewipe; \
	done
.if !defined(NOPORTDOCS)
	for i in README Changes blue1.gif dot.ewipe sample.ewp; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ewipe; \
	done
.endif

.include <bsd.port.mk>
