# New ports collection makefile for:	freeglut
# Date created:		Wed Apr 23 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		freeglut
PORTVERSION=		2.4.0
CATEGORIES=		x11-toolkits
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		An alternative to the OpenGL Utility Toolkit (GLUT) library

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=		yes
USE_XLIB=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--x-includes=${X11BASE}/include	\
			--x-libraries=${X11BASE}/lib
CONFIGURE_ENV=		CPPFLAGS="-I${X11BASE}/include" LDFLAGS="-lusbhid"

USE_REINPLACE=		yes
REINPLACE_ARGS=		-i ""

PKGMESSAGE=		${WRKDIR}/pkg-message
SUB_FILES=		pkg-message

DOCS=	download.html freeglut.html freeglut_logo.png		\
	freeglut_user_interface.html index.html ogl_sm.png	\
	progress.html structure.html
BINS=	CallbackMaker Fractals Fractals_random Lorenz One shapes

.include <bsd.port.pre.mk>

pre-configure:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e "s|-Werror||" ${WRKSRC}/configure
.endif
.for fract in /fractals.c _random/fractals_random.c
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g"		\
		${WRKSRC}/progs/demos/Fractals${fract}
.endfor

post-build:
	@${MV} ${WRKSRC}/progs/demos/CallbackMaker/.libs/CallbackMaker	\
		${WRKSRC}/progs/demos/CallbackMaker/.libs/callbackmaker

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
.for prog in ${BINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/progs/demos/${prog}/.libs/${prog:L} \
		${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} |	\
		${SED} -e "s|/usr/local|${PREFIX}|"		\
			-e "s|/usr/X11R6|${X11BASE}|"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
