# New ports collection makefile for:	vmd
# Date created:		12 August 2004
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=		vmd
PORTVERSION=		1.8.2
CATEGORIES=		science graphics python tcl84 tk84
MASTER_SITES=		#
DISTFILES=		${PORTNAME}-${PORTVERSION}.src.tar.gz

MAINTAINER=		stephen@math.missouri.edu
COMMENT=		A molecular visualization program

BUILD_DEPENDS=		${PYNUMERIC}
LIB_DEPENDS=		tcl84:${PORTSDIR}/lang/tcl84 \
			tk84:${PORTSDIR}/x11-toolkits/tk84 \
			fltk:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=		${PYNUMERIC}

USE_PERL5_BUILD=	yes
USE_GMAKE=		yes
USE_GL=			yes
USE_PYTHON=		yes
USE_REINPLACE=		yes

# I.A.N.A.L. so this may be overly restrictive.
NO_PACKAGE=		"License has restrictions"
NO_CDROM=		"License has restrictions"
RESTRICTED=		"License has restrictions"

.include <bsd.port.pre.mk>

# Check for VMD sources
.if !exists(${DISTDIR}/${DISTFILES}) # && !defined(PACKAGE_BUILDING)
ECHO_MSG=	/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access\n\
http://www.ks.uiuc.edu/Development/Download/download.cgi?PackageName=VMD\n\
with a web browser.  You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the University of Illinois agreement, download the source file,\n\
${DISTFILES}.  Please place this file in ${DISTDIR}.\n
.endif

post-patch:
	${REINPLACE_CMD} "s/-lpthread/${PTHREAD_LIBS}/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/-ltk8.4/-ltk84/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/-ltcl8.4/-ltcl84/" ${WRKSRC}/configure
	${REINPLACE_CMD} "s%\$$python_dir/lib_\$$config_arch%${PREFIX}%" ${WRKSRC}/configure
	${REINPLACE_CMD} "s/python2.2/${PYTHON_VERSION}/" ${WRKSRC}/configure

do-build:
	cd ${WRKDIR}/plugins && ${SETENV} ${MAKE_ENV} PLUGINDIR=${WRKSRC}/plugins ${GMAKE} FREEBSD distrib
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} TCL_INCLUDE_DIR=${PREFIX}/include/tcl8.4 TK_INCLUDE_DIR=${PREFIX}/include/tk8.4 ${GMAKE} freebsd.opengl
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} all

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} install

.include <bsd.port.post.mk>
