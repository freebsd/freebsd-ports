# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	form
PORTVERSION=	4.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Symbolic Manipulation System

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf gmake
USE_GITHUB=	yes
GNU_CONFIGURE=	yes

GH_ACCOUNT=	vermaseren

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

CONFIGURE_ARGS+=	--enable-scalar \
			--enable-largefile \
			--with-api=posix

post-build-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual; ${MAKE_CMD} html pdf)

post-install-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/manual/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
