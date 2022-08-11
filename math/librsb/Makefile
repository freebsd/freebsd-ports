PORTNAME=	librsb
PORTVERSION=	1.3.0.1
CATEGORIES=	math
MASTER_SITES=	SF/librsb
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/-rc/}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Sparse matrix library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		bash:shells/bash

USES=		fortran gmake libtool shebangfix
INSTALL_TARGET=	install-strip
TEST_TARGET=	qtests
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-lthr
SHEBANG_FILES=	*.sh */*.sh

OPTIONS_DEFINE=	DOCS OPTIMIZE

OPTIMIZE_DESC=		Optimize for the local machine
OPTIMIZE_CONFIGURE_ENV=	SPCFLAGS="${CFLAGS:N-O*}"

post-patch:
	@${REINPLACE_CMD} -E s/sed/gsed/g ${WRKSRC}/*.sh ${WRKSRC}/*/*.sh

post-patch-OPTIMIZE-on:
	@${REINPLACE_CMD} s/enable_optimize=no/enable_optimize=yes/ \
		${WRKSRC}/configure

.include <bsd.port.mk>
