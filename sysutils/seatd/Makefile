# $FreeBSD$

PORTNAME=	seatd
DISTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Minimal seat management daemon and universal library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 meson pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
MESON_ARGS=	-Dbuiltin=enabled # SUID fallback
PLIST_FILES=	bin/${PORTNAME} \
		include/libseat.h \
		lib/libseat.so \
		lib/libseat.so.1 \
		libdata/pkgconfig/libseat.pc

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch:
# hier(7) doesn't define /run, so use /var/run
	@${REINPLACE_CMD} -e 's,/run,/var&,' \
		${WRKSRC}/libseat/backend/seatd.c \
		${WRKSRC}/man/seatd.1.scd \
		${WRKSRC}/seatd/seatd.c
# realpath(3) expands /dev/dri/ to /dev/drm/
	@${REINPLACE_CMD} -e 's,/dev/dri,/dev/drm,' \
		-e '/prefix/ { s/card//; s/renderD//; }' \
		${WRKSRC}/common/drm.c

.include <bsd.port.mk>
