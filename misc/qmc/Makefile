# ex:ts=8
# New ports collection makefile for:	qmc
# Date created:			Nov 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qmc
PORTVERSION=	0.94
CATEGORIES=	misc
MASTER_SITES=	http://qmc.pollaknet.at/program/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quine-McClusky process simplification tool

USE_BZIP2=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/qmc

.if !defined(WITHOUT_TCLTK)
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
PLIST_FILES+=	bin/qmc-gui
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| wish | ${LOCALBASE}/bin/wish8.4 |g' ${WRKSRC}/qmc-gui.tcl

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -I. *.cc -o qmc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qmc ${PREFIX}/bin/qmc
.if !defined(WITHOUT_TCLTK)
	${INSTALL_SCRIPT} ${WRKSRC}/qmc-gui.tcl ${PREFIX}/bin/qmc-gui
.endif

.include <bsd.port.mk>
