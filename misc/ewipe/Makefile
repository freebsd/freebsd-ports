# New ports collection makefile for:	ewipe
# Version required:	1.0.0
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.13 1998/06/27 05:19:18 asami Exp $
#

DISTNAME=	ewipe-1.0.0
CATEGORIES=	misc tk42
MASTER_SITES=	http://www.jnet-jp.to/~sekisita/ewipe/

MAINTAINER=	itojun@itojun.org

#RUN_DEPENDS=	wish4.2:${PORTSDIR}/x11-toolkits/tk42

TCLLIBS=	definefont.tcl edittable.tcl setpointer.tcl viewer.tcl tclIndex
DOCS=		README Changes dot.ewipe
SAMPLES=	a1.gif a2.gif a3.gif a4.gif blue1.gif sample.ewp test.ewp \
		tutorial.ewp

KANJI?=		no

do-build:
.if ${KANJI} != yes
	for i in edittable.tcl ewipe viewer.tcl; do\
		ed ${WRKSRC}/$$i < ${SCRIPTDIR}/nokanji.ed;\
	done
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/ewipe
	${INSTALL_SCRIPT} ${WRKSRC}/ewipe ${PREFIX}/bin
	for i in ${TCLLIBS}; do\
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
