PORTNAME=	seatd
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Minimal seat management daemon and universal library
WWW=		https://git.sr.ht/~kennylevinsen/seatd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe meson pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
CPE_VENDOR=	${PORTNAME}_project
MESON_ARGS=	-Dlibseat-logind=disabled
SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		"@(,video,4750) bin/${PORTNAME}-launch" \
		include/libseat.h \
		lib/libseat.so \
		lib/libseat.so.1 \
		libdata/pkgconfig/libseat.pc

OPTIONS_DEFINE=	BASU MANPAGES
OPTIONS_DEFAULT=BASU MANPAGES
OPTIONS_SUB=	yes

# https://lists.sr.ht/~kennylevinsen/seatd-devel/%3CQHZRRQ.73ZI29COPK131%40unrelenting.technology%3E
BASU_DESC=		ConsoleKit2 support via basu (experimental)
BASU_PATCH_SITES=	https://github.com/DankBSD/${PORTNAME}/commit/:ck2
BASU_PATCHFILES=	5f31d8eebea1.patch:-p1:ck2
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_MESON_ON=		-Dlibseat-consolekit2=enabled
.if make(makesum)
.MAKEFLAGS:		WITH+=BASU
.endif

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man1/${PORTNAME}-launch.1.gz

.include <bsd.port.mk>
