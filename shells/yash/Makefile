PORTNAME=	yash
DISTVERSION=	2.60
CATEGORIES=	shells
MASTER_SITES=	https://github.com/magicant/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	POSIX-compliant command line shell
WWW=		https://magicant.github.io/yash/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:xz
USE_CSTD=	c99

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime localbase:ldflags
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
