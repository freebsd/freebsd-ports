# New ports collection makefile for:	mmosaic
# Date created:				2000-12-26
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mmosaic
PORTVERSION=	3.7.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/
DISTNAME=	mMosaic-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

NO_CDROM=	"academic, research and internal business purposes only, without a fee"
NO_PACKAGE=	"must cause any work...derived...to be licensed as a whole...under...this License"
PLIST=		${WRKDIR}/pkg-plist
USE_MOTIF=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mMosaic-src-${PORTVERSION}

pre-install:
	${ECHO} bin/mmosaic > ${PLIST}
	cd ${WRKSRC}/Copyrights; for i in `find * -type f`; do \
		${ECHO} share/doc/mmosaic/$${i} >> ${PLIST}; \
	done

do-install:
	${MKDIR} ${PREFIX}/share/doc/mmosaic/
	${INSTALL_DATA} ${WRKSRC}/Copyrights/* ${PREFIX}/share/doc/mmosaic/
#	${INSTALL_DATA} ${WRKSRC}/app-def/app-defaults.color ${PREFIX}/lib/X11/app-defaults/mMosaic
	${INSTALL_PROGRAM} ${WRKSRC}/src/mMosaic ${PREFIX}/bin/mmosaic

.include <bsd.port.mk>
