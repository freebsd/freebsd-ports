# New ports collection makefile for:	freeglut
# Date created:		Wed Apr 23 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		freeglut
PORTVERSION=		2.0.0
CATEGORIES=		x11-toolkits
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alternative to the OpenGL Utility Toolkit (GLUT) library

USE_AUTOMAKE=	yes
USE_AUTOHEADER=	yes
HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_XLIB=	yes
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"			\
		ACLOCAL="${ACLOCAL}"				\
		AUTOCONF="${AUTOCONF}"				\
		AUTOMAKE="${AUTOMAKE}"				\
		AUTOHEADER="${AUTOHEADER}"

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

DOCS=	download.html freeglut.html freeglut_logo.png		\
	freeglut_user_interface.html index.html ogl_sm.png	\
	progress.html structure.html
BINS=	fractals fractals_random lorenz one

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/X11R6|${X11BASE}|g"	\
			-e "s|/usr/local|${LOCALBASE}|g"	\
		${WRKSRC}/aclocal.m4
.for fract in /fractals.c _random/fractals_random.c
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g"	\
		${WRKSRC}/progs/demos/Fractals${fract}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/progs/demos/Fractals/fractals.dat	\
		${EXAMPLESDIR}
.for FILE in ${BINS}
	@${MV} ${PREFIX}/bin/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.else
.for FILE in ${BINS}
	@${RM} ${PREFIX}/bin/${FILE}
.endfor
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} |	\
		${SED} -e "s|/usr/local|${PREFIX}|"		\
			-e "s|/usr/X11R6|${X11BASE}|"
	@${ECHO_MSG}

.include <bsd.port.mk>
