# New ports collection makefile for:	pose
# Date created:			Sat May  6 14:03:08 CEST 2000
# Whom:				Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pose
PORTVERSION=	3.1
CATEGORIES=	palm emulators
MASTER_SITES=	http://www.palmos.com/dev/tech/tools/emulator/
# DISTNAME=	emulator_src_31
DISTFILES=	emulator_src_31.tar.gz emulator_skins_16.tar.gz

MAINTAINER=	wlloyd@slap.net

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_MESA=	yes
WRKSRC=		${WRKDIR}/Emulator_Src_${PORTVERSION}/BuildUnix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"

post-install:
	${MKDIR} ${PREFIX}/share/pose
	${INSTALL_DATA} "${WRKSRC}/../ROMTransfer/Source/ROM_Transfer.prc" ${PREFIX}/share/pose
	@${SED} -e 's#/usr/local#${PREFIX}#g' ${PKGMESSAGE}
	${CP} -Rp ${WRKDIR}/Skins_v1.6 ${PREFIX}/share/pose/skins

.include <bsd.port.mk>
