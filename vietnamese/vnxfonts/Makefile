# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	vnxfonts
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	Xfonts
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	X fonts for displaying Vietnamese

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

WRKSRC=		${WRKDIR}/fonts/X
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/vietnamese
	@cd ${WRKSRC} ; \
		${INSTALL_DATA} fonts.dir *.pcf.Z  \
		${PREFIX}/lib/X11/fonts/vietnamese
	@${INSTALL_DATA} ${FILESDIR}/fonts.alias \
		${PREFIX}/lib/X11/fonts/vietnamese
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
