# New ports collection makefile for:	pose
# Date created:			Sat May  6 14:03:08 CEST 2000
# Whom:				Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pose
PORTVERSION=	3.5
PORTREVISION=	6
CATEGORIES=	palm emulators
MASTER_SITES=	http://www.palmos.com/dev/tools/emulator/sources/ \
		http://www.palmos.com/dev/tools/emulator/:skins
DISTFILES=	emulator_src_3.5.tar.gz \
		emulator-skins-19.tar.gz:skins

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Palm OS(R) Emulator

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_GL=		yes
USE_PERL5_BUILD=yes
WRKSRC=		${WRKDIR}/Emulator_Src_${PORTVERSION}/BuildUnix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x --with-fltk=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		CFLAGS=-DBROKEN_VIRTUAL_DEFAULT_ARGUMENTS=1 \
		LIBS="${PTHREAD_LIBS}"
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

post-install:
	${MKDIR} ${PREFIX}/share/pose
	${INSTALL_DATA} "${WRKSRC}/../ROMTransfer/Source/ROM_Transfer.prc" ${PREFIX}/share/pose
	@${SED} -e 's#/usr/local#${PREFIX}#g' ${PKGMESSAGE}
	${CP} -Rp ${WRKDIR}/Skins_v1.9 ${PREFIX}/share/pose/skins

.include <bsd.port.post.mk>
