# New ports collection makefile for:	lesstif
# Version required:	0.84
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $Id: Makefile,v 1.17 1998/03/28 14:12:55 steve Exp $
#

DISTNAME=	lesstif-0.84
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/  \
		ftp://ftp.hungry.com/pub/hungry/lesstif/srcdist/

MAINTAINER=	ports@FreeBSD.org

#	see below for shared lib version information

MANUAL_PACKAGE_BUILD=	do not want to install during interactive build
GNU_CONFIGURE=  yes
# comment this and remove the strip statement in post-install for debugging
CONFIGURE_ARGS=	--disable-debug
USE_X11=	yes

.if defined(HAVE_MOTIF)
IS_INTERACTIVE=	yes
pre-fetch:
	@${ECHO} "***********************************************************"
	@${ECHO} "*                      W a r n i n g                      *"
	@${ECHO} "* This port will overwrite your Motif installation.       *"
	@${ECHO} "***********************************************************"
	@${ECHO} -n "Is this ok? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
	        return 0; \
	        ;; \
	    *) \
	        ${ECHO} "Okay, I won't install it then...."; \
	        ${ECHO} "(Don't worry about the following \"*** Error code 1\"s)"; \
	        return 1; \
	        ;; \
	  esac)
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/X11/mwm ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/system.mwmrc \
		${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/alt.map ${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/Motif-1.2/mwm/Mwm \
		${PREFIX}/lib/X11/app-defaults/Mwm
	/usr/bin/strip ${PREFIX}/lib/libXm.so.1.2 ${PREFIX}/lib/libMrm.so.1.2
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

#	Shared lib versions
#	dist version		BSD shared lib version
#	------------		----------------------
#	0.78			0.0
#	0.79			0.1
#	0.80			0.1
#       0.83			1.2
