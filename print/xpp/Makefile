# New ports collection makefile for: 	xpp
# Date created:		3 Oct 2001
# Whom:			Daniel O'Connor <doconnor@gsoft.com.au>
#
# $FreeBSD$
#

PORTNAME=	xpp
PORTVERSION=	1.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cups

MAINTAINER=	doconnor@gsoft.com.au

LIB_DEPENDS=	cups:${PORTSDIR}/print/cups \
		fltk:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lcups -lfltk \
			-lGL -lXext ${PTHREAD_LIBS:S/"//g}" \
		CPPFLAGS=-I${LOCALBASE}/include

post-install:
	$(MKDIR) $(PREFIX)/share/doc/xpp
	$(INSTALL_DATA) $(WRKSRC)/README $(PREFIX)/share/doc/xpp

.include <bsd.port.mk>
