# Ports collection makefile for: spin
# Date created:		Oct 23, 1997
# Whom:			jhanna@home.com
#
# $FreeBSD$
#

PORTNAME=	spin
PORTVERSION=	3.3.10
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/spin/ \
		ftp://www.netlib.org/spin/ \
		ftp://ftp.freesoftware.com/pub/netlib/spin/
DISTFILES=	spin3310.tar.gz html.tar.gz

MAINTAINER=	jhanna@home.com

DIST_SUBDIR=	spin
WRKSRC=		${WRKDIR}/Src3.3
MAKEFILE=	makefile
ALL_TARGET=	spin

post-extract:
	@cd ${WRKDIR}/Test && ${SH} ${WRKDIR}/Test/examples

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKDIR}/Xspin3.3/xspin3310.tcl

pre-build:
	cd ${WRKSRC} && ${MAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/Xspin3.3/xspin3310.tcl ${PREFIX}/bin
	${RM} -f ${PREFIX}/bin/xspin
	${LN} -s ${PREFIX}/bin/xspin3310.tcl ${PREFIX}/bin/xspin

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/spin/Doc
	${MKDIR} ${PREFIX}/share/doc/spin/Examples
	${MKDIR} ${PREFIX}/share/doc/spin/HTML
	${MKDIR} ${PREFIX}/share/doc/spin/Test
	${INSTALL_DATA} ${WRKDIR}/Doc/* ${PREFIX}/share/doc/spin/Doc
	${INSTALL_DATA} ${WRKDIR}/Test/ex.* ${PREFIX}/share/doc/spin/Examples
	${INSTALL_DATA} ${WRKDIR}/HTML/* ${PREFIX}/share/doc/spin/HTML
.for i in README.tests abp erathostenes hello leader leader.ltl leader2 \
	loops pathfinder peterson petersonN pftp priorities snoopy sort
	${INSTALL_DATA} ${WRKDIR}/Test/$i ${PREFIX}/share/doc/spin/Test
.endfor
.endif

.include <bsd.port.mk>
