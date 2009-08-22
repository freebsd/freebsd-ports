# ex:ts=8
# New ports collection makefile for:	tightvnc
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tightvnc
PORTVERSION=	1.3.10
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/vnc-tight/TightVNC-unix/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}_unixsrc

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Enhanced version of VNC

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	showrgb:${PORTSDIR}/x11/rgb \
		xauth:${PORTSDIR}/x11/xauth \
		xorg-fonts>=7.2:${PORTSDIR}/x11-fonts/xorg-fonts

CONFLICTS=	tridiavnc-[0-9]* vnc-[0-9]*

WRKSRC=		${WRKDIR}/vnc_unixsrc

USE_BZIP2=	yes
USE_PERL5=	yes
USE_IMAKE=	yes
USE_XORG=	xaw
ALL_TARGET=	World
NO_INSTALL_MANPAGES=	yes

MAN1=		Xvnc.1 vncviewer.1 vncpasswd.1 vncconnect.1 vncserver.1

OPTIONS=	JVNC_VIEWER "Install Java-based vnc viewer" off

#.include <bsd.port.pre.mk>

### use me when 5.5, 6.1, 6.2R die or we do impement something in b.p.m
.include <bsd.port.options.mk>

.ifdef(WITH_JVNC_VIEWER)
USE_JAVA=	yes
JAVA_RUN=	yes
PLIST_SUB+=	JVNC_VIEWER=""
.else
PLIST_SUB+=	JVNC_VIEWER="@comment "
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/share/vnc/classes/index.vnc)
IGNORE=		vnc has already been installed, please uninstall it first
.endif

post-patch:
.for file in vncviewer/Imakefile Xvnc/config/cf/vnclibs.def
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s,/usr/local/vnc/classes,${DATADIR}/classes,g ; \
		s,^#!/usr/bin/perl,#!${PERL},g" ${WRKSRC}/vncserver
	@${PERL} -pi -e "s,%%CC%%,${CC},g ; \
		s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/Xvnc/config/cf/FreeBSD.cf

do-install:
	@(cd ${WRKSRC}; ./vncinstall ${PREFIX}/bin ${PREFIX}/man)
.for FILE in Xvnc vncviewer vncpasswd vncconnect
	@${STRIP_CMD} ${PREFIX}/bin/${FILE}
.endfor
.ifdef(WITH_JVNC_VIEWER)
	@${MKDIR} ${DATADIR}/classes
	${INSTALL_DATA} ${WRKSRC}/classes/*.* ${DATADIR}/classes
.endif

.include <bsd.port.post.mk>
