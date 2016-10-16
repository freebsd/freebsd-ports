# $FreeBSD$

PORTNAME=	l-smash
PORTVERSION=	2.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	MP4 muxer and other tools

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
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/SHARED/,/^$$/ { /STRIP/s/-x //; }' \
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
