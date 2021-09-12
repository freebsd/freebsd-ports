PORTNAME=	seatd
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/commit/
PATCHFILES+=	d5c1a7811bf7.patch:-p1 # seatd-launch: respect PATH when looking for command
PATCHFILES+=	483dbf76faf9.patch:-p1 # seatd-launch: Use optind to find the command
PATCHFILES+=	8c85c46d2db9.patch:-p1 # man/seatd-launch: Make mssage about root clearer

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Minimal seat management daemon and universal library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 meson pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		"@(,video,4750) bin/${PORTNAME}-launch" \
		include/libseat.h \
		lib/libseat.so \
		lib/libseat.so.1 \
		libdata/pkgconfig/libseat.pc

OPTIONS_DEFINE=	BASU MANPAGES SUID
OPTIONS_DEFAULT=BASU MANPAGES SUID

# https://lists.sr.ht/~kennylevinsen/seatd-devel/%3CQHZRRQ.73ZI29COPK131%40unrelenting.technology%3E
BASU_DESC=		ConsoleKit2 support via basu (experimental)
BASU_PATCH_SITES=	https://github.com/DankBSD/${PORTNAME}/commit/:ck2
BASU_PATCHFILES=	c35529dd761d.patch:-p1:ck2 76ccbf3617da.patch:-p1:ck2
BASU_LIB_DEPENDS=	libbasu.so:devel/basu
BASU_USES=		localbase # https://github.com/emersion/basu/issues/36
BASU_MESON_ENABLED=	libseat-consolekit2
.if make(makesum)
.MAKEFLAGS:		WITH+=BASU
.endif

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man1/${PORTNAME}-launch.1.gz

SUID_DESC=		Fall back to builtin server when running as root
SUID_MESON_ENABLED=	libseat-builtin

.include <bsd.port.mk>
