# New ports collection makefile for:	eroaster
# Date Created:		20 Dic 2003
# Whom:			Davide D'Amico <dave@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	eroaster
PORTVERSION=	2.2.0.0.6
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/Development/2.2.0-0.6
DISTNAME=	${PORTNAME}-2.2.0-0.6

MAINTAINER=	dave@gufi.org
COMMENT=	A GNOME2 frontend to mkisofs/cdrecord

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/_gnome.so:${PORTSDIR}/x11-toolkits/py-gnome2

.if defined(WITH_ADDITIONAL_PROGRAMS)
BUILD_DEPENDS+=	bchunk:${PORTSDIR}/sysutils/bchunk \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		lame:${PORTSDIR}/audio/lame \
		mpg123:${PORTSDIR}/audio/mpg123 \
		normalize:${PORTSDIR}/audio/normalize \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		sox:${PORTSDIR}/audio/sox \
		${PYTHON_SITELIBDIR}/cdrom.so:${PORTSDIR}/audio/py-cddb
.endif

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_CDRTOOLS=	yes

pre-everything::
	@${ECHO_MSG} "===>  You can enable more features by defining WITH_ADDITIONAL_PROGRAMS"
	@${ECHO_MSG} "===>"

post-patch::
	@cd ${WRKSRC} && ${RM} process.py.orig
	@${REINPLACE_CMD} -e 's|share/applets/Utility|share/gnome/apps/Utilities|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's| --activate-goad-server=eroaster||' ${WRKSRC}/eroaster.desktop
	@${REINPLACE_CMD} -e 's|whrandom|random|' ${WRKSRC}/gnometools.py
	@${RM} ${WRKSRC}/gnometools.py.bak

.include <bsd.port.mk>
