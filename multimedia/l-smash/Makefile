PORTNAME=	l-smash
PORTVERSION=	2.14.5
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MP4 muxer and other tools
WWW=		https://l-smash.github.io/l-smash/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

USES=		gmake pathfix
PATHFIX_MAKEFILEIN=	Makefile
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--cc="${CC}" \
		--extra-cflags="${CPPFLAGS} ${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}" \
		--extra-libs="${LIBS}" \
		--enable-shared
MAKE_ARGS=	STRIP="${STRIP_CMD}"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/-Os //; /=.*-fexcess-precision/d' \
		-e '/sed/{s/-i/& ""/; s/i \\/&\\"$$'"'\\\n'"'"/; s/%"/&$$'"'\\\012'"'/;}' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/SHARED/,/^$$/ { /STRIP/s/-x //; }' \
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
