# New ports collection makefile for:	lfpfonts-var
# Date created:				Sat Jan 19 20:44:52 CET 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lfpfonts-var
PORTVERSION=	0.83
CATEGORIES=	x11-fonts
MASTER_SITES=	http://dreamer.nitro.dk/linux/lfp/

MAINTAINER=	olgeni@FreeBSD.org

WRKSRC=		${WRKDIR}/lfpfonts-var

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/lfpfonts-var
	${INSTALL_DATA} ${WRKSRC}/lfp-var/*.pcf.gz ${PREFIX}/lib/X11/fonts/lfpfonts-var
	${INSTALL_DATA} ${WRKSRC}/lfp-var/fonts.dir ${PREFIX}/lib/X11/fonts/lfpfonts-var

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.post.mk>
