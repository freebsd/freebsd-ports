# ex:ts=8
# New ports collection makefile for:	tightvnc
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tightvnc
PORTVERSION=	1.2.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vnc-tight
DISTNAME=	${PORTNAME}-${PORTVERSION}_unixsrc

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/misc/10x20.pcf.gz:${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/vnc_unixsrc
USE_IMAKE=	yes
USE_XPM=	yes
USE_PERL5=	yes
ALL_TARGET=	World
NO_INSTALL_MANPAGES=	yes
XFREE86_HTML_MAN=	no

MAN1=		Xvnc.1 vncviewer.1 vncpasswd.1 vncconnect.1 vncserver.1

.if exists(${X11BASE}/share/vnc/classes/index.vnc)
IGNORE=		"vnc has already been installed, please uninstall it first."
.endif

post-patch:
.for file in vncviewer/Imakefile Xvnc/config/cf/vnclibs.def
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s,/usr/local/vnc/classes,${DATADIR}/classes,g ; \
		s,^#!/usr/bin/perl,#!${PERL},g" ${WRKSRC}/vncserver
	@${PERL} -pi -e "s,%%CC%%,${CC},g ; \
		s,%%CFLAGS%%,${CFLAGS},g" ${WRKSRC}/Xvnc/config/cf/FreeBSD.cf

do-install:
	@(cd ${WRKSRC}; ./vncinstall ${PREFIX}/bin ${PREFIX}/man)
.for file in Xvnc vncviewer vncpasswd vncconnect
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
	@${MKDIR} ${DATADIR}/classes
	${INSTALL_DATA} ${WRKSRC}/classes/*.* ${DATADIR}/classes

.include <bsd.port.mk>
