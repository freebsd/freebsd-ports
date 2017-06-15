# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openquicktime
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/OpenQuicktime%20v1/${PORTVERSION}b
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable library for handling Apple's QuickTime(TM) files

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USES=		gmake jpeg tar:tgz
USE_LDCONFIG=	yes
PKGDEINSTALL=	${PKGINSTALL}

CFLAGS_aarch64=	-fPIC
CFLAGS_amd64=	-fPIC

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_OFF=	--enable-debug=no

post-patch:
	@${REINPLACE_CMD} -e 's|xCC|xc| ; s|-O2|| ; s|-fpic||' \
		-e 's|ftello64|ftello| ; s|fseeko64|fseeko|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E 's,(bin|lib|include)dir),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/audioplugin/MP3/Makefile.in \
		${WRKSRC}/videoplugin/PHOTO_JPEG/Makefile.in
	@${REINPLACE_CMD} -e 's|"m"|"g"|' \
		${WRKSRC}/audioplugin/MP3/audioencoder/lame3.70/quantize-pvt.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
