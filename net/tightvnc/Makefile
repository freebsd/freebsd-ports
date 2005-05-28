# ex:ts=8
# New ports collection makefile for:	tightvnc
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tightvnc
PORTVERSION=	1.2.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vnc-tight
DISTNAME=	${PORTNAME}-${PORTVERSION}_unixsrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced version of VNC

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/misc/10x20.pcf.gz:${X_FONTS_MISC_PORT}

WRKSRC=		${WRKDIR}/vnc_unixsrc

USE_BZIP2=	yes
USE_PERL5=	yes
USE_IMAKE=	yes
USE_XPM=	yes
ALL_TARGET=	World
NO_INSTALL_MANPAGES=	yes
XFREE86_HTML_MAN=	no

MAN1=		Xvnc.1 vncviewer.1 vncpasswd.1 vncconnect.1 vncserver.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

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
		s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/Xvnc/config/cf/FreeBSD.cf

do-install:
	@(cd ${WRKSRC}; ./vncinstall ${PREFIX}/bin ${PREFIX}/man)
.for FILE in Xvnc vncviewer vncpasswd vncconnect
	@${STRIP_CMD} ${PREFIX}/bin/${FILE}
.endfor
	@${MKDIR} ${DATADIR}/classes
	${INSTALL_DATA} ${WRKSRC}/classes/*.* ${DATADIR}/classes

.include <bsd.port.post.mk>
