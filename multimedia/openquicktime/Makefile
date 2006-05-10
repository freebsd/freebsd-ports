# New ports collection makefile for:	openquicktime
# Date created:				Mon Sep 24 16:26:33 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openquicktime
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openquicktime
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable library for handling Apple's QuickTime(TM) files

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
PKGDEINSTALL=	${PKGINSTALL}

OPTIONS=	DEBUG "Turn on debugging" on

.include <bsd.port.pre.mk>

.ifndef(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=no
.endif

.if ${ARCH} != "i386"
BROKEN=		"Does not build on !i386"
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|xCC|xc|' \
		-e 's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if ${OSVERSION} >= 502126
	@${REINPLACE_CMD} \
		-e 's|-fpic||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
