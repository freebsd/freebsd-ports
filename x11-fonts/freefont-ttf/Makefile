# Ports collection makefile for:	freefont-ttf
# Date created:				2005-12-17
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		freefont-ttf
PORTVERSION=		20090104
CATEGORIES=		x11-fonts
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	freefont

MAINTAINER=		pgollucci@FreeBSD.org
COMMENT=		Free UCS Outline Fonts

BUILD_DEPENDS=		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
			mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

MAKE_JOBS_SAFE=  yes

WRKSRC=			${WRKDIR}/freefont-${PORTVERSION}
INSTALLDIR=		${PREFIX}/lib/X11/fonts/${PORTNAME}

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontscale
	cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontdir

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
.endif
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC} && \
	${INSTALL_DATA} fonts.dir fonts.scale *.ttf ${INSTALLDIR}

.include <bsd.port.mk>
