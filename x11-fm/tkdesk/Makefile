# New ports collection makefile for:	tkdesk
# Version required:     1.0b5
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.4 1997/04/20 13:19:59 wosch Exp $
#

DISTNAME=	tkdesk-1.0b5
CATEGORIES=	misc x11 tk80
MASTER_SITES=	http://people.mainz.netsurf.de/~bolik/tkdesk/ \
		ftp://ftp.neosoft.com/pub/tcl/sorted/unknown/

MAINTAINER=	dmlb@ragnet.demon.co.uk

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11/tk80 \
		tcl80\\.1\\.:${PORTSDIR}/lang/tcl80

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	TCLCONF_PATH=${PREFIX}/lib/tcl8.0 TKCONF_PATH=${PREFIX}/lib/tk8.0
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

post-install:
	strip ${PREFIX}/bin/tkdesksh
	strip ${PREFIX}/bin/tkdeskclient

.include <bsd.port.mk>
