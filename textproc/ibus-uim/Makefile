PKGNAMEPREFIX=	ibus-

COMMENT=	IBus engine of uim input method

LIB_DEPENDS=	libuim.so:textproc/uim \
		libibus-1.0.so:textproc/ibus

MASTERDIR=	${.CURDIR}/../../textproc/uim
PKGDIR=		${.CURDIR}
CONFIGURE_ARGS=	--with-ibus

UIM_SLAVE=	yes

.if defined(WITHOUT_X11)
IGNORE=		requires X11
.endif

PLIST_FILES=	libexec/ibus-engine-uim \
		share/ibus/component/uim.xml

do-build:
	(cd ${WRKSRC}/ibus && ${SETENV} ${MAKE_ENV} ${MAKE_CMD})

do-install:
	(cd ${WRKSRC}/ibus && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} DESTDIR=${STAGEDIR} install-strip)

.include "${MASTERDIR}/Makefile"
