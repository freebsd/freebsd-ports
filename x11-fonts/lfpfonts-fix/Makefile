# New ports collection makefile for:	lfpfonts-fix
# Date created:				Sat Jan 19 20:59:31 CET 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lfpfonts-fix
PORTVERSION=	0.82
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xfonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Fixed width fonts from the Linux Font Project

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}

WRKSRC=		${WRKDIR}/lfpfonts-fix

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/lfpfonts-fix
	@${INSTALL_DATA} ${WRKSRC}/lfp-fix/*.pcf.gz ${PREFIX}/lib/X11/fonts/lfpfonts-fix
	@${INSTALL_DATA} ${WRKSRC}/lfp-fix/fonts.dir ${PREFIX}/lib/X11/fonts/lfpfonts-fix

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
