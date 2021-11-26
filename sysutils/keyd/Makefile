PORTNAME=	keyd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Key remapping daemon for evdev

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libudev.so:devel/libudev-devd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}
GH_ACCOUNT=	rvaiya
MAKE_ARGS=	DESTDIR="${DESTDIR}" PREFIX="${PREFIX}" \
		GIT_HASH="${DISTVERSIONFULL}"
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		"@dir ${ETCDIR}"

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's,/var/lock,/var/run,' \
		-e 's,/usr/local,${LOCALBASE},' \
		-e '/systemd/d' \
		-e '/^CFLAGS/s/=/+=/' \
		-e '/-l/s/$$/ $$(LDFLAGS)/' \
		-e 's/ -O3//' \
		${WRKSRC}/Makefile
# https://lists.freebsd.org/pipermail/freebsd-x11/2019-March/023097.html
	@${REINPLACE_CMD} -e 's,__FreeBSD,&_disabled,' \
		${WRKSRC}/src/config.h \
		${WRKSRC}/src/keys.h \
		${WRKSRC}/src/main.c \
		${NULL}

.include <bsd.port.mk>
