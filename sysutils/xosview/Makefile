# ex:ts=8
# Ports collection makefile for:  xosview
# Date created:			  19 Nov 1997
# Whom:				  Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	xosview
PORTVERSION=	1.8.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A graphical performance meter

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
MAN1=		xosview.1

post-patch:
	@${REINPLACE_CMD} -e 's,iostream.h,iostream,' \
		${WRKSRC}/xwin.h \
		${WRKSRC}/Host.h \
		${WRKSRC}/Xrm.cc \
		${WRKSRC}/llist.cc \
		${WRKSRC}/timeval.h \
		${WRKSRC}/xosview.cc
	@${REINPLACE_CMD} -e 's,string.h,string,' \
		${WRKSRC}/xwin.h \
		${WRKSRC}/Host.cc \
		${WRKSRC}/Xrm.cc \
		${WRKSRC}/llist.cc \
		${WRKSRC}/timeval.h \
		${WRKSRC}/xosview.cc
	@${REINPLACE_CMD} -e 's,fstream.h,fstream,' \
		${WRKSRC}/bitfieldmeter.cc \
		${WRKSRC}/fieldmeter.cc \
		${WRKSRC}/fieldmeterdecay.cc \
		${WRKSRC}/fieldmetergraph.cc
	@${REINPLACE_CMD} -e 's,-O4 -pipe,,' \
		${WRKSRC}/configure

.include <bsd.port.mk>
