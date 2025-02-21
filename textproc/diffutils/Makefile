PORTNAME=	diffutils
DISTVERSION=	3.11
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	schaiba@gmail.com
COMMENT=	GNU differential compare utilities
WWW=		https://www.gnu.org/software/diffutils/diffutils.html

LICENSE=	GPLv3+

USES=		charsetfix cpe tar:xz
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
TEST_TARGET=	check

INFO=		diffutils

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=nls

post-patch:
	@${REINPLACE_CMD} -e '/^mkdir/s:@mkdir_p@:${MKDIR}:' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
