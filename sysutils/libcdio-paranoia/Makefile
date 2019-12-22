# $FreeBSD$

PORTNAME=	libcdio-paranoia
PORTVERSION=	10.2+2.0.1
CATEGORIES=	sysutils
MASTER_SITES=	GNU/libcdio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Read audio from the CDROM directly as data

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcdio.so:sysutils/libcdio

USES=		compiler:c11 gmake libtool localbase pathfix perl5 pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-patch:
	${REINPLACE_CMD} -e 's|/jp/man1|/ja/man1|' \
		${WRKSRC}/doc/ja/Makefile.in
	${REINPLACE_CMD} -e 's|freebsd10\.\*|freebsd[1-9][0-9].*|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
