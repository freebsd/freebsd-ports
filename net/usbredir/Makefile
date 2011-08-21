# Ports collection makefile for: usbredir
# Date created: Mon Aug 15 18:16:38 CEST 2011
# Whom:         Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	usbredir
PORTVERSION=	0.3
CATEGORIES=	net devel
MASTER_SITES=	http://people.fedoraproject.org/~jwrdegoede/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	A protocol for redirection of USB traffic

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
PATCH_STRIP=	-p1
MAKE_ARGS+=	PREFIX=${PREFIX}

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800069
IGNORE=		needs libusb 1.0
.else
MAKE_ENV+=	PKG_CONFIG_PATH=${FILESDIR}
.endif

post-patch:
	@${REINPLACE_CMD} "s|\\\$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|" ${WRKSRC}/*/Makefile

.include <bsd.port.mk>
