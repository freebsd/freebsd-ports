# New ports collection makefile for:	guiTAR
# Version required:		0.1.4
# Date created:			Sat Aug 14 1999
# Whom:				domi@saargate.de
#
# $Id$
#

DISTNAME=	guiTAR-0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://disq.bir.net.tr/guitar/ \
		http://artemis.efes.net/disq/guitar/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.3:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

GTK_CONFIG?=    ${X11BASE}/bin/gtk12-config
CONFIGURE_ENV=  GTK_CONFIG="${GTK_CONFIG}"

.if defined(NO_GNOME)
CONFIGURE_ARGS	+=	--disable-gnome
.else
LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs
.endif

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/guitar ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${SCRIPTDIR}/bsdtar2gnutar ${PREFIX}/bin

.include <bsd.port.mk>
