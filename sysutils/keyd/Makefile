PORTNAME=	keyd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Key remapping daemon for evdev

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libudev.so:devel/libudev-devd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase:ldflags
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
		-e '/systemd/d' \
		-e '/^CFLAGS/s/=/+=/' \
		-e '/-l/s/$$/ $$(LDFLAGS)/' \
		-e 's/ -O3//' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/config.h
	@${REINPLACE_CMD} -e 's,/var/lock,/var/run,' \
		${WRKSRC}/src/main.c

.include <bsd.port.mk>
