# New ports collection makefile for:	freeglut
# Date created:		Wed Apr 23 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	freeglut
PORTVERSION=	1.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${SNAPDATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alternative to the OpenGL Utility Toolkit (GLUT) library

SNAPDATE=	2002-01-25

USE_AUTOMAKE=	yes
HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_XLIB=	yes
USE_GNOME=	glib12
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include `${GLIB_CONFIG} --cflags`"	\
		LDFLAGS="`${GLIB_CONFIG} --libs`"

WRKSRC=		${WRKDIR}/${PORTNAME}-0.1

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

MK2X11=		freeglut-1.3/Makefile.am genfonts/Makefile.am

post-patch:
.for file in ${MK2X11}
	@${REINPLACE_CMD} -e "s|%%X11BASE%%|${X11BASE}|g" ${WRKSRC}/${file}
.endfor

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "     freeglut requires a DRI enabled-graphic card;"
	@${ECHO_MSG} "     You may try to run the program 'one' to check your installation."
	@${ECHO_MSG}

.include <bsd.port.mk>
