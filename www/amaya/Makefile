# New ports collection makefile for:	amaya
# Version required:	1.4a
# Date created:		26 Dec 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.1.1.1 1999/01/10 18:54:23 steve Exp $
#

DISTNAME=	amaya-src-1.4a
PKGNAME=	amaya-1.4a
CATEGORIES= 	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://ftp-eu.w3.org/pub/amaya/

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

REQUIRES_MOTIF=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/Thot/obj

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--with-amaya

post-extract:
	${MKDIR} ${WRKSRC}

post-configure:
	${CP} ${WRKSRC}/Options.orig ${WRKSRC}/Options

post-install:
.for file in amaya print
	strip ${PREFIX}/thot/applis/bin/${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/../amaya/COPYRIGHT.html ${PREFIX}/thot/amaya/

.include <bsd.port.mk>
