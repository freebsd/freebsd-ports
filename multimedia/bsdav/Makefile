# New ports collection makefile for:   bsdav
# Date created:        2005-11-04
# Whom:                Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
# $Id: Makefile,v 1.8 2005/11/19 23:21:24 itetcu Rel $
#

PORTNAME=	bsdav
PORTVERSION=	1.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.jakemsr.com/bsdav/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	BSD native set of programs for audio and video reading and writing

IGNORE=		does not work. We need to import bktv patches from OpenBSD to make it work
DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2006-12-01

INSTALLS_SHLIB=	yes

MAN1=		audiorec.1 bktrrec.1 bsdavdemux.1 bsdavrec.1 btv.1 tunerctl.1
MAN5=		bsdav.5
PORTDOCS=	README

OPTIONS=	X11 "Build and install player progs (brings X libs)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
MAN1+=		avplay.1 bktrplay.1 bsdavplay.1
PLIST_SUB+=	X11=""
.else
MAKE_ENV+=	NO_X11=true
PLIST_SUB+=	X11="@comment "
.endif

.if !( defined(NO_PORTDOCS) || defined(NOPORTDOCS) )
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
