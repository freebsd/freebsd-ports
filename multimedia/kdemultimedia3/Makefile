# New ports collection makefile for:	KDE2 Multimedia
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

RUN_DEPENDS=	xanim:${PORTSDIR}/graphics/xanim
LIB_DEPENDS+=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_KDELIBS_VER=3
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e 's@values\.h@limits.h@' \
		${WRKSRC}/mpeglib/lib/util/render/x11/x11Surface.h \
		${WRKSRC}/mpeglib/lib/util/render/x11/imageDeskX11.h
	@${PERL} -pi -e 's@\bMAXINT\b@INT_MAX@g' \
		${WRKSRC}/mpeglib/lib/util/render/x11/x11Surface.cpp \
		${WRKSRC}/mpeglib/lib/util/render/x11/imageDeskX11.cpp
.if ${MACHINE_ARCH} == "alpha"
	@${PERL} -pi -e "s@-ffast-math@@g" ${WRKSRC}/kmidi/Makefile.in
.endif

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "In order to run the kscd program properly, please run as root:"
	@${ECHO_MSG}
	@${ECHO_MSG} " # ${LN} -sf <cdrom_device> /dev/cdrom"
	@${ECHO_MSG} " # ${CHMOD} 666 <cdrom_device>"
	@${ECHO_MSG}
	@${ECHO_MSG} "to link and give permission to access the CD-ROM device."
	@${ECHO_MSG} "For example, if you have an IDE/ATAPI CD-ROM device:"
	@${ECHO_MSG}
	@${ECHO_MSG} " # ${LN} -sf /dev/racd0c /dev/cdrom"
	@${ECHO_MSG} " # ${CHMOD} 666 /dev/racd0c"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
