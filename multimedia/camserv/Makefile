# New ports collection makefile for:	camserv
# Date created:         Sat 22 July 2000
# Whom:                 Chuck Hein <chein@freebsd.org> & Jim Overholt <overholt@isdw.net>
#
# $FreeBSD$
#

PORTNAME=	camserv
PORTVERSION=	0.5.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://cserv.sourceforge.net/old/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Camserv is a free program to do streaming video via the web

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_LIB=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${X11BASE}/include/gtk12 -I${X11BASE}/include/gdk-pixbuf-1.0 \
		-I${LOCALBASE}/include/glib12" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/javascript.txt ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>
  
.if ${OSVERSION} < 500000
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	alpha i386 ia64
.endif

.include <bsd.port.post.mk>
