# New ports collection makefile for:	lfpfonts-var
# Date created:				Sat Jan 19 20:44:52 CET 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lfpfonts-var
PORTVERSION=	0.83
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xfonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Variable width fonts from the Linux Font Project

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}

WRKSRC=		${WRKDIR}/lfpfonts-var

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/lfpfonts-var
	@${INSTALL_DATA} ${WRKSRC}/lfp-var/*.pcf.gz ${PREFIX}/lib/X11/fonts/lfpfonts-var
	@${INSTALL_DATA} ${WRKSRC}/lfp-var/fonts.dir ${PREFIX}/lib/X11/fonts/lfpfonts-var

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
