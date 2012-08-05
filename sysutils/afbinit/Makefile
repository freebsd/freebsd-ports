# Ports collection makefile for:	afbinit
# Date created:				15 September 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=		afbinit
PORTVERSION=		1.0
PORTREVISION=		4
CATEGORIES=		sysutils graphics
MASTER_SITES=		${MASTER_SITE_DEBIAN:S/$/:afbinit,patch/} \
			http://dlc.sun.com/%SUBDIR%/:microcode
MASTER_SITE_SUBDIR=	pool/contrib/a/afbinit/:afbinit,patch \
			osol/sparc-gfx/downloads/:microcode
DISTFILES=		${PORTNAME}_${PORTVERSION}.orig.tar.gz:afbinit \
			afb-ucode.tar.bz2:microcode
DIST_SUBDIR=		${PORTNAME}

PATCH_SITES=		${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=		${PORTNAME}_${PORTVERSION}-4.diff.gz:patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=		marius@FreeBSD.org
COMMENT=		Sun AFB aka Sun Elite 3D microcode firmware loader

ONLY_FOR_ARCHS=		sparc64
USE_RC_SUBR=		afbinit
WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig
PKGMESSAGE=		${WRKDIR}/pkg-message

MAN8=			afbinit.8

post-patch:
.for i in afbinit.c debian/afbinit.8
	@${REINPLACE_CMD} -E -e 's|\/usr\/lib|${DATADIR}|g; \
		s|(\/dev\/fb\[)[0-3]+(\])|\10-7\2|g; \
		s|\/etc\/init.d\/afbinit|${PREFIX}/etc/rc.d/afbinit\{,.sh\}|g' \
		${WRKSRC}/${i}
.endfor
	@${SED} 's|%%DATADIR%%|${DATADIR}|g' ${PKGDIR}/pkg-message > \
		${WRKDIR}/pkg-message

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o afbinit afbinit.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/afbinit ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/debian/afbinit.8 ${PREFIX}/man/man8
	@${INSTALL} -d ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/afb-ucode/afb.ucode ${DATADIR}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/afb-ucode/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
