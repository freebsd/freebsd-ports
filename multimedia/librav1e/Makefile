PORTREVISION=	2
PKGNAMEPREFIX=	lib

MASTERDIR=	${.CURDIR}/../rav1e
PLIST=		${.CURDIR}/pkg-plist

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

PLIST_FILES=	# empty
PLIST_SUB=	VERSION=${DISTVERSION:C/-.*//}

do-build:
	@${CARGO_CARGO_RUN} cbuild \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	@${CARGO_CARGO_RUN} cinstall \
		--verbose \
		--verbose \
		--destdir "${STAGEDIR}" \
		--prefix "${PREFIX}" \
		${CARGO_INSTALL_ARGS}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include "${MASTERDIR}/Makefile"
