PKGNAMESUFFIX=	-wayland

COMMENT=	uim input method for Wayland zwp_input_method_v1

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libuim.so:textproc/uim \
		libwayland-client.so:graphics/wayland

USES=		desktop-file-utils

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-wayland

UIM_SLAVE=	yes

PLIST_FILES=	bin/uim-wayland \
		share/applications/uim-wayland.desktop

do-build:
	(cd ${WRKSRC}/wayland && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/wayland && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR} install-strip)

.include "${MASTERDIR}/Makefile"
