# New ports collection makefile for:    jmk-x11-fonts
# Date created:         Sat Aug 19 20:36:34 CEST 2000
# Whom:                 olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	jmk-x11-fonts
PORTVERSION=	3.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.ntrnet.net/~jmknoble/fonts/

MAINTAINER=	olgeni@FreeBSD.org

USE_IMAKE=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/jmk
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${PREFIX}/lib/X11/fonts/jmk
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/jmk

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.post.mk>
