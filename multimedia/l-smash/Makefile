PORTNAME=	l-smash
DISTVERSIONPREFIX=	v
DISTVERSION=	2.18.0-10
DISTVERSIONSUFFIX=	-g2c0696c
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MP4 muxer and other tools
WWW=		https://l-smash.github.io/l-smash/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libobuparse.so:multimedia/obuparse

USES=		gmake localbase pathfix
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	vimeo

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--cc="${CC}" \
		--extra-cflags="${CPPFLAGS} ${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}" \
		--extra-libs="${LIBS}" \
		--enable-shared
MAKE_ARGS=	STRIP="${STRIP_CMD}"

post-patch:
	@${REINPLACE_CMD} -e 's/-Os //; /=.*-fexcess-precision/d' \
		-e '/sed/{s/-i/& ""/; s/i \\/&\\"$$'"'\\\n'"'"/; s/%"/&$$'"'\\\012'"'/;}' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/SHARED/,/^$$/ { /STRIP/s/-x //; }' \
		${WRKSRC}/${MAKEFILE}

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/liblsmash.a

.include <bsd.port.mk>
