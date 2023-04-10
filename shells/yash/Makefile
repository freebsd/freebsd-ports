PORTNAME=	yash
DISTVERSION=	2.54
CATEGORIES=	shells
MASTER_SITES=	OSDN/yash \
		https://github.com/magicant/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	POSIX-compliant command line shell
WWW=		https://yash.osdn.jp/index.html.en

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz
USE_CSTD=	c99

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime localbase:ldflags
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
