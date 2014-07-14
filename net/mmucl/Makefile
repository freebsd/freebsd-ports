# Created by: Matt Heckaman <matt@LUCIDA.QC.CA>
# $FreeBSD$

PORTNAME=	mmucl
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	tim@SPYDERWEB.COM.AU
COMMENT=	Powerful GUI MUD client written in TCL

LIB_DEPENDS=	libtcl84.so:${PORTSDIR}/lang/tcl84
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USES=		gmake
MAKE_ARGS=	BASE_DIR=${PREFIX} TCLSH=tclsh8.4 INFO_DIR=${PREFIX}/info \
		INSTALL_INFO=/usr/bin/install-info
INFO=		mmucl

NO_STAGE=	yes
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}

.include <bsd.port.mk>
