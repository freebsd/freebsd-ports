# New ports collection makefile for:	tridiavnc
# Date created:		14 June 2001
# Whom:			dwcjr
#
# $FreeBSD$
#

PORTNAME=	tridiavnc
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dwcjr
DISTNAME=	DevVNC_unix
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display X and Win32 desktops on remote X/Win32/Java displays

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/unix/vnc_unixsrc
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xt xpm
ALL_TARGET=	World
NO_INSTALL_MANPAGES=	yes
XFREE86_HTML_MAN=	no

CONFLICTS=	tightvnc-[0-9]* vnc-[0-9]*

.include <bsd.port.pre.mk>

.if ${ARCH} != i386
BROKEN=		Does not compile on ${MACHINE_ARCH}
.endif

post-patch:
.for file in vncviewer/Imakefile Xvnc/config/cf/vnclibs.def Xvnc/config/cf/Imake.tmpl
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s,/usr/local/vnc/classes,${DATADIR}/classes,g ; \
		s,^#!/usr/bin/perl,#!${PERL},g" ${WRKSRC}/vncserver

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect ${PREFIX}/bin/vncconnect
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
# Go install Java classes
	${MKDIR} ${PREFIX}/share/vnc
	${CP} -R ${WRKSRC}/classes ${PREFIX}/share/vnc

.include <bsd.port.post.mk>
