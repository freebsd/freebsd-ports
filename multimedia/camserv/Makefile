# New ports collection makefile for:	camserv
# Date created:         Sat 22 July 2000
# Whom:                 Chuck Hein <chein@freebsd.org> & Jim Overholt <overholt@isdw.net>
#
# $FreeBSD$
#

PORTNAME=	camserv
PORTVERSION=	0.42
CATEGORIES=	multimedia
MASTER_SITES=	http://cserv.sourceforge.net/old/

MAINTAINER=	chein@freebsd.org
COMMENT=	Camserv is a free program to do streaming video via the web

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

# Things that should get fixed
#
# imlib2 still needs to be ported
# http://www.us.rasterman.com/files/imlib2-0.0.5.tar.gz
# imlib2:${PORTSDIR}/graphics/imlib2
#
# gtk12 has broken includes ...
# should look something like this :
# include <gtk12/gdk/gdkprivate.h>
# instead of <gdk/gdkprivate.h>

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/camserv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/camserv
	${INSTALL_DATA} ${WRKSRC}/javascript.txt ${PREFIX}/share/doc/camserv
.endif

.include <bsd.port.post.mk>
