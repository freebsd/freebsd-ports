# New ports collection makefile for:	pose
# Date created:			Sat May  6 14:03:08 CEST 2000
# Whom:				Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pose
PORTVERSION=	3.0a6
CATEGORIES=	palm emulators
MASTER_SITES=	http://www.palmos.com/dev/tech/tools/emulator/
DISTNAME=	emulator_src_30a6

MAINTAINER=	dirk@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		GL.14:${PORTSDIR}/graphics/Mesa3

WRKSRC=		${WRKDIR}/Emulator_Src_${PORTVERSION}/BuildUnix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib

post-install:
	${MKDIR} ${PREFIX}/share/pose
	${INSTALL_DATA} "${WRKSRC}/../ROMTransfer/Source/ROM Transfer.prc" ${PREFIX}/share/pose
	@${SED} -e 's#/usr/local#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.mk>
