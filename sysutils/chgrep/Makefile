PORTNAME=	chgrep
DISTVERSION=	1.2.5
CATEGORIES=	sysutils

MAINTAINER=	se@FreeBSD.org
COMMENT=	Fast string substitution across multiple files
WWW=		https://github.com/jose1711/chgrep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	jose1711
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/chgrep share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
