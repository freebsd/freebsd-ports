# ex:ts=8
# New ports collection makefile for:	tightvnc
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tightvnc
PORTVERSION=	1.2.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vnc-tight
DISTNAME=	${PORTNAME}-${PORTVERSION}_unixsrc

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/vnc_unixsrc
USE_IMAKE=	yes
ALL_TARGET=	World
NO_INSTALL_MANPAGES=	yes

.if exists(${X11BASE}/share/vnc/classes/index.vnc)
IGNORE=		"vnc has already been installed, please uninstall it first."
.endif

post-patch:
.for file in vncviewer/Imakefile Xvnc/config/cf/vnclibs.def
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s,/usr/local/vnc/classes,${DATADIR}/classes,g ; \
		s,^#!/usr/bin/perl,#!${PERL},g" ${WRKSRC}/vncserver

do-install:
	@(cd ${WRKSRC}; ./vncinstall ${PREFIX}/bin)
.for file in Xvnc vncviewer vncpasswd vncconnect
	@strip ${PREFIX}/bin/${file}
.endfor
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/classes ${DATADIR}

.include <bsd.port.mk>
