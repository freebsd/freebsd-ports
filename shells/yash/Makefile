PORTNAME=	yash
DISTVERSION=	2.54
CATEGORIES=	shells
MASTER_SITES=	https://osdn.net/projects/yash/downloads/78345/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	POSIX-compliant command line shell
WWW=		https://yash.osdn.jp/index.html.en

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# skip interposed HTML page
FETCH_ARGS=	--user-agent=curl/7.68.0

USES=		tar:xz

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
CPPFLAGS+=	-std=c99

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime localbase:ldflags
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
