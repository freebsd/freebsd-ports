# New ports collection makefile for:	ewipe
# Version required:	0.6.0
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.6 1997/12/05 03:14:59 itojun Exp $
#

DISTNAME=	ewipe0.6.0
PKGNAME=	ja-ewipe-0.6.0
CATEGORIES=	japanese misc
MASTER_SITES=	http://al.ei.tuat.ac.jp/~sekisita/ewipe/

MAINTAINER=	itojun@itojun.org

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/ewipe
	${MKDIR} ${PREFIX}/share/doc/ewipe
	${INSTALL_SCRIPT} ${WRKSRC}/ewipe ${PREFIX}/bin
	for i in edittable.tcl setpointer.tcl viewer.tcl tclIndex; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/lib/ewipe; \
	done
.if !defined(NOPORTDOCS)
	for i in README Changes blue1.gif dot.ewipe sample.ewp; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ewipe; \
	done
.endif

.include <bsd.port.mk>
