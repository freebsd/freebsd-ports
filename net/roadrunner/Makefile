# New ports collection makefile for:    roadrunner
# Date created:                        	26 January 2003
# Whom: 				Yann Berthier <yb@sainte-barbe.org>
#
# $FreeBSD$
#

PORTNAME=	roadrunner
PORTVERSION=	0.9.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.codefactory.se/pub/RoadRunner/source/roadrunner/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	yb@sainte-barbe.org
COMMENT=	A portable BEEP protocol implementation

USE_GNOME=	glib20 libxml2
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -pthread"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

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
