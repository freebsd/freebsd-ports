# New ports collection makefile for:	lesstif
# Version required:	0.77
# Date created:		December 10, 1996
# Whom:			1wardd@airmail.net
#
# $Id: Makefile,v 1.3 1997/02/19 06:33:59 asami Exp $
#

DISTNAME=	lesstif-0.77
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/lesstif/

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
	${MKDIR} ${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/mwm/system.mwmrc \
		${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/mwm/alt.map ${PREFIX}/lib/X11/mwm
	${INSTALL_DATA} ${WRKSRC}/clients/mwm/Mwm \
		${PREFIX}/lib/X11/app-defaults/Mwm
	/usr/bin/strip ${PREFIX}/lib/libXm.so.0.0 ${PREFIX}/lib/libMrm.so.0.0
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
