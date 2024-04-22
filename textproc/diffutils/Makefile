PORTNAME=	diffutils
PORTVERSION=	3.8
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GNU

LICENSE=	GPLv3+

MAINTAINER=	schaiba@gmail.com
COMMENT=	GNU differential compare utilities
WWW=		https://www.gnu.org/software/diffutils/diffutils.html

LIB_DEPENDS=	libsigsegv.so:devel/libsigsegv

USES=		charsetfix cpe tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=g
TEST_TARGET=	check
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=nls

INFO=		diffutils

post-patch:
	@${REINPLACE_CMD} -e '/^mkdir/s:@mkdir_p@:${MKDIR}:' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
