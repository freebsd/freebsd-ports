# New ports collection makefile for:	KDE2 Multimedia
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	2.1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

RUN_DEPENDS=	xanim:${PORTSDIR}/graphics/xanim
LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2

USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lstdc++ -lgcc" \
		USER_LDFLAGS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lstdc++ -lgcc"
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e 's,kscd_compile=no,kscd_compile=yes,g; \
			s,DO_NOT_COMPILE mpeglib_artsplug,DO_NOT_COMPILE,g; \
			s,DO_NOT_COMPILE mpeglib,DO_NOT_COMPILE,g' ${WRKSRC}/configure

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "To run kscd program, as root, please run"
	@${ECHO_MSG}
	@${ECHO_MSG} " % ${LN} -sf <cdrom_device> /dev/cdrom"
	@${ECHO_MSG} " % ${CHMOD} 666 <cdrom_device>"
	@${ECHO_MSG}
	@${ECHO_MSG} "to link and give permission to access the CD-ROM device."
	@${ECHO_MSG}
	@${ECHO_MSG} "For example(IDE CD-ROM device):"
	@${ECHO_MSG} " % ${LN} -sf /dev/racd0c /dev/cdrom"
	@${ECHO_MSG} " % ${CHMOD} 666 /dev/racd0c"
	@${ECHO_MSG}

.include <bsd.port.mk>
