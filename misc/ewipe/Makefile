# New ports collection makefile for:	ewipe
# Version required:	0.7.0
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.9 1998/02/13 02:48:12 itojun Exp $
#

DISTNAME=	ewipe0.7.0
PKGNAME?=	ewipe-0.7.0
CATEGORIES=	misc
MASTER_SITES=	http://al.ei.tuat.ac.jp/~sekisita/ewipe/

MAINTAINER=	itojun@itojun.org

RUN_DEPENDS=	wish4.2:${PORTSDIR}/x11/tk42

NO_BUILD=	yes
NO_CONFIGURE=	yes

DOCS=		README Changes dot.ewipe
SAMPLES=	a1.gif a2.gif a3.gif a4.gif blue1.gif sample.ewp \
		sample2.ewp sample3.ewp tutorial.ewp

do-install:
	${MKDIR} ${PREFIX}/lib/ewipe
	${INSTALL_SCRIPT} ${WRKSRC}/ewipe ${PREFIX}/bin
	for i in edittable.tcl setpointer.tcl viewer.tcl tclIndex; do\
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/lib/ewipe;\
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ewipe
	${MKDIR} ${PREFIX}/share/doc/ewipe/sample
	for i in ${DOCS}; do\
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ewipe;\
	done
	for i in ${SAMPLES}; do\
		${INSTALL_DATA} ${WRKSRC}/sample/$$i \
			${PREFIX}/share/doc/ewipe/sample;\
	done
.endif

.include <bsd.port.mk>
