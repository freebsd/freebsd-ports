# New ports collection makefile for:	lesstif
# Version required:	0.80public
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $Id: Makefile,v 1.11 1997/07/03 06:31:46 tg Exp $
#

DISTNAME=	lesstif-0.80public
PKGNAME=	lesstif-0.80
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.lesstif.org/pub/hungry/lesstif/  \
		ftp://ftp.hungry.com/pub/hungry/lesstif/

MAINTAINER=	ports@FreeBSD.org

#	see below for shared lib version information

GNU_CONFIGURE=  yes
USE_X11=	yes
# change this and remove the strip statement in post-install for debugging
CONFIGURE_ENV=	CCFLAGS="-O -pipe"

.if defined(HAVE_MOTIF)
IS_INTERACTIVE=	yes
pre-fetch:
	@echo "***********************************************************"
	@echo "*                      W a r n i n g                      *"
	@echo "* This port will overwrite your Motif installation.       *"
	@echo "***********************************************************"
	@echo -n "Is this ok? (y/n) ==> "
	@(read ans; \
	  case x"$$ans" in \
	    xy*|xY*) \
	        return 0; \
	        ;; \
	    *) \
	        echo "Okay, I won't install it then...."; \
	        echo "(Don't worry about the following \"*** Error code 1\"s)"; \
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
	/usr/bin/strip ${PREFIX}/lib/libXm.so.0.1 ${PREFIX}/lib/libMrm.so.0.1
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>


#	Shared lib versions
#	dist version		BSD shared lib version
#	------------		----------------------
#	0.78			0.0
#	0.79			0.1
#	0.80			0.1
