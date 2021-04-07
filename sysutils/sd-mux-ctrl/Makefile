PORTNAME=	sd-mux-ctrl
DISTVERSION=	g20200217
CATEGORIES=	sysutils
MASTER_SITES=	https://git.tizen.org/cgit/tools/testlab/sd-mux/snapshot/sd-mux-9dd189d973da64e033a0c5c2adb3d94b23153d94.tar.bz2?/

PATCH_SITES=	https://github.com/emaste/sd-mux/commit/
PATCHFILES=	83f2783ac56bbf42f9bb877c5937cd1f17bb2999.patch:-p1

MAINTAINER=	emaste@FreeBSD.org
COMMENT=	Control utility for Tizen SD card multiplexer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libpopt.so:devel/popt

USES=		cmake pkgconfig tar:bz2

WRKSRC=		${WRKDIR}/sd-mux-9dd189d973da64e033a0c5c2adb3d94b23153d94

PLIST_FILES=	bin/sd-mux-ctrl

.include <bsd.port.mk>
