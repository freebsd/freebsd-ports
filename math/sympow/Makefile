# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	sympow
PORTVERSION=	2.023.6
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mathematical program for SYMmetric POWer elliptic curve L-functions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man	\
		bash:shells/bash
LIB_DEPENDS=	libpari.so:math/pari

USES=		compiler:c++11-lang gmake shebangfix
SHEBANG_FILES=	${CONFIGURE_SCRIPT}

USE_GITLAB=	yes
GL_ACCOUNT=	rezozer/forks
GL_COMMIT=	7fd4d97cabc07951200b98ee841afc4151c2c287

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure

post-build:
	for file in `${LS} ${WRKSRC}/datafiles/*.txt`; do	\
		${WRKSRC}/sympow -txt2bin "`${GREP} -c AT $${file}`" <$${file} $${file%txt}bin; \
	done

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/datafiles/*.bin ${STAGEDIR}${DATADIR}/datafiles

.include <bsd.port.mk>
