# New ports collection makefile for:  rat
# Date created:			      3 July 1999
# Whom:				      O.Hodson@cs.ucl.ac.uk (Orion Hodson)
#
# $FreeBSD$
#

PORTNAME=	rat
PORTVERSION=	4.2.13
PORTREVISION=	0
CATEGORIES=	mbone audio ipv6
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/4.2.13/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cpiazza

MAINTAINER=	O.Hodson@cs.ucl.ac.uk

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_AUTOCONF=	yes
USE_GMAKE=	yes
MAN1=		rat.1
MANCOMPRESSED=	no

RAT_BUILD_DIRS=	common rat

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
ENABLE_IPv6=	--enable-ipv6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rat/rat ${PREFIX}/bin/rat
	${INSTALL_PROGRAM} ${WRKSRC}/rat/rat-ui ${PREFIX}/bin/rat-ui
	${INSTALL_PROGRAM} ${WRKSRC}/rat/rat-media ${PREFIX}/bin/rat-media
	${INSTALL_MAN}  ${WRKSRC}/rat/man/man1/rat.1 ${PREFIX}/man/man1
	${MKDIR} ${LOCALBASE}/etc/sdr/plugins
	${INSTALL_DATA} ${WRKSRC}/rat/sdr2.plugin.S02.audio.rtp.*.rat ${LOCALBASE}/etc/sdr/plugins

do-build:
.for d in ${RAT_BUILD_DIRS}
	cd ${WRKSRC}/${d} && ${GMAKE}
.endfor

do-configure:
	cd ${WRKSRC}/common && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS} ${ENABLE_IPv6}
	cd ${WRKSRC}/rat && ${AUTOCONF} && ./configure ${CONFIGURE_ARGS} --with-tcl=${LOCALBASE} --with-tk=${LOCALBASE} ${ENABLE_IPv6}

.include "bsd.port.post.mk"
