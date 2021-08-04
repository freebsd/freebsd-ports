PORTNAME=	keyd
PORTVERSION=	s20210803
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
GH_TAGNAME=	f5d0c04
MAKE_ENV=	CPATH="${LOCALBASE}/include" \
		LIBRARY_PATH="${LOCALBASE}/lib"
MAKE_ARGS=	DESTDIR="${DESTDIR}" PREFIX="${PREFIX}" \
		GIT_HASH="${GH_TAGNAME:U${DISTVERSIONFULL}}"
CFLAGS+=	-D_WITH_GETLINE # XXX Remove after FreeBSD 11 EOL
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		"@dir ${ETCDIR}"

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e '/systemd/d' \
		-e '/^CFLAGS/s/=/+=/' \
		-e 's/ -O3//' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/config.h
	@${REINPLACE_CMD} -e 's,/var/lock,/var/run,' \
		${WRKSRC}/src/main.c

.include <bsd.port.mk>
