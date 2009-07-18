# New ports collection makefile for:	openquicktime
# Date created:				Mon Sep 24 16:26:33 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openquicktime
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openquicktime
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable library for handling Apple's QuickTime(TM) files

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_LDCONFIG=	yes
PKGDEINSTALL=	${PKGINSTALL}

OPTIONS=	DEBUG "Turn on debugging" off

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=no
.endif

.if ${OSVERSION} < 700000
BROKEN=		Does not install
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|xCC|xc| ; s|-O2||' \
		-e 's|ftello64|ftello| ; s|fseeko64|fseeko|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|"m"|"g"|' \
		${WRKSRC}/audioplugin/MP3/audioencoder/lame3.70/quantize-pvt.c
	@${REINPLACE_CMD} \
		-e 's|-fpic||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
