# ex:ts=8
# Ports collection makefile for:    VN-Xfonts
# Version required:     1.1.1
# Date created:         Tue Dec 3, 1996
# Whom:                 David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#
#	version # is VISCII version supported + .<edit_revision>

PORTNAME=	vnxfonts
PORTVERSION=	1.1.1
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	Xfonts
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/fonts/X
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/vietnamese
	@cd ${WRKSRC} ; \
		${INSTALL_DATA} fonts.dir *.pcf.Z  \
		${PREFIX}/lib/X11/fonts/vietnamese
	@${INSTALL_DATA} ${FILESDIR}/fonts.alias \
		${PREFIX}/lib/X11/fonts/vietnamese
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
