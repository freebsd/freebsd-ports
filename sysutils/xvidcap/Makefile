# New ports collection makefile for:	xvidcap
# Date created:		Sat 24 April 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		xvidcap
DISTVERSION=		1.1.4p1
PORTREVISION=	8
PORTEPOCH=		1
CATEGORIES=		sysutils multimedia
MASTER_SITES=		SF/${PORTNAME}/OldFiles

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Capture your X display to individual frames or MPEG video

BUILD_DEPENDS=		rarian-sk-config:${PORTSDIR}/textproc/rarian	\
			xml2po:${PORTSDIR}/textproc/gnome-doc-utils	\
			texi2html:${PORTSDIR}/textproc/texi2html
# To be reactivated when ffmpeg-devel will install libswscale.
#LIB_DEPENDS=		avutil.1:${PORTSDIR}/multimedia/ffmpeg-devel
LIB_DEPENDS=		mp3lame.0:${PORTSDIR}/audio/lame
RUN_DEPENDS=		animate:${PORTSDIR}/graphics/ImageMagick

GNU_CONFIGURE=		yes
# Remove MAKE="${GMAKE}" after ffmpeg-devel's upgrade
CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
			LDFLAGS="-L${LOCALBASE}/lib"	\
			MAKE="${GMAKE}"
CONFIGURE_ARGS=		-with-forced-embedded-ffmpeg	# To be removed after ffmpeg-devel's upgrade

USE_GMAKE=		yes	# To be removed after ffmpeg-devel's upgrade
USE_GNOME=		glib20 libglade2
USE_GETTEXT=		yes
USE_XORG=		x11 xmu
INSTALLS_OMF=		yes

.if !defined(CFLAGS) || ${CFLAGS:M-fno-strict-aliasing*} == ""
CFLAGS+=	-O2 -fno-strict-aliasing
.endif

PORTDOCS=		AUTHORS ChangeLog README
NULLDOCS=		COPYING

MAN1=			xvidcap.1

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|pkgdataDATA install-xvidcapdocDATA|pkgdataDATA|'	\
		${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${RM} ${NULLDOCS:S|^|${DOCSDIR}/|}
.endif

.include <bsd.port.mk>
