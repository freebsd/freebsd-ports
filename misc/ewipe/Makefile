# New ports collection makefile for:	ewipe
# Date created:		17 October 1997
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	ewipe
PORTVERSION=	1.1.0
CATEGORIES+=	misc tk42
MASTER_SITES=	http://www.jnet-jp.to/~sekisita/ewipe/ \
		http://freefall.freebsd.org/~itojun/distfiles/

MAINTAINER?=	ports@freebsd.org

#RUN_DEPENDS=	wish4.2:${PORTSDIR}/x11-toolkits/tk42

NO_BUILD=	YES
TCLLIBS=	definefont.tcl edittable.tcl setpointer.tcl viewer.tcl tclIndex
DOCS=		README Changes.jp dot.ewipe
SAMPLES=	a1.gif a2.gif a3.gif a4.gif blue1.gif sample.ewp test.ewp \
		tutorial.ewp

KANJI?=		no

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
