# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-go

COMMENT=	Go module for NGINX Unit

USES=		go

PLIST_FILES=	# reset to empty
PLIST_DIRS=	# reset to empty
PLIST=	${.CURDIR}/pkg-plist

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

CGO_CFLAGS+=	-I${WRKSRC}/src -I${WRKSRC}/build

post-extract:
	${MKDIR} ${GO_WRKSRC:H}
	${LN} -sf ${WRKSRC}/src/go/unit ${GO_WRKSRC}

post-configure:
	cd ${WRKSRC} && env ${GO_ENV} ./configure go

pre-build:
	cd ${WRKSRC} && make go

post-install:
	@true # override master's

.include "${MASTERDIR}/Makefile"
