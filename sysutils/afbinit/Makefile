# Ports collection makefile for:	afbinit
# Date created:				15 September 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=		afbinit
PORTVERSION=		1.0
PORTREVISION=		1
CATEGORIES=		sysutils graphics
MASTER_SITES=		${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/contrib/a/afbinit
DISTNAME=		${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=		${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=		${PORTNAME}_${PORTVERSION}-1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		marius@FreeBSD.org
COMMENT=		Sun AFB aka Sun Elite 3D microcode firmware loader

ONLY_FOR_ARCHS=		sparc64
USE_REINPLACE=		yes
WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
PKGMESSAGE=		${WRKDIR}/pkg-message

MAN8=			afbinit.8

post-patch:
.for i in afbinit.c debian/afbinit.8 debian/afbinit.init
	@${REINPLACE_CMD} -E -e 's|\/usr\/lib|${DATADIR}|g; \
		s|(\/dev\/fb\[)[0-3]+(\])|\10-7\2|g; \
		s|\/etc\/init.d\/afb|${PREFIX}/etc/afbinit.sh|g; \
		s|\/usr\/sbin|${PREFIX}/sbin|g' ${WRKSRC}/${i}
.endfor
	@${SED} 's|%%DATADIR%%|${DATADIR}|g' ${PKGDIR}/pkg-message > \
		${WRKDIR}/pkg-message

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o afbinit afbinit.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/afbinit ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/debian/afbinit.8 ${PREFIX}/man/man8
	@${INSTALL_SCRIPT} ${WRKSRC}/debian/afbinit.init \
		${PREFIX}/etc/rc.d/afbinit.sh
	@${INSTALL} -d ${DATADIR}

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
