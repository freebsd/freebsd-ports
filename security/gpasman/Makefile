# New ports collection makefile for:	gpasman
# Date created:			Mon Mai 10 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	gpasman
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://gpasman.sourceforge.net/files/

MAINTAINER=	domi@saargate.de
COMMENT=	A password manager that stores password information encrypted

PLIST_FILES=	bin/gpasman
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTKCONFIG="${GTK_CONFIG}"

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/src/gpasman ${PREFIX}/bin

.include <bsd.port.mk>
