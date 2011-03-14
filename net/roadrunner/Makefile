# New ports collection makefile for:    roadrunner
# Date created:                        	26 January 2003
# Whom: 				Yann Berthier <yb@sainte-barbe.org>
#
# $FreeBSD$
#

PORTNAME=	roadrunner
PORTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://ftp.codefactory.se/pub/RoadRunner/source/roadrunner/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable BEEP protocol implementation

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GNOME=	glib20 libxml2 pkgconfig
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GMAKE=	yes
USE_LDCONFIG=	yes
NOT_FOR_ARCHS=	sparc64

DOC_FILES=	API_CHANGES AUTHORS COPYING ChangeLog \
		LICENSE NEWS README README.announce

post-install:
	cd ${WRKSRC}/tests/.libs && ${INSTALL_PROGRAM} \
	rr-client rr-server ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOC_FILES} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} \
	dataflow.dia design.dia ${DOCSDIR}
.endif

.include <bsd.port.mk>
