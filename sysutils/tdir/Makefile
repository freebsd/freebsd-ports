PORTNAME=	tdir
PORTVERSION=	1.73
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tundraware.com/Software/tdir/

MAINTAINER=	tdir@tundraware.com
COMMENT=	Advanced file directory display utility

LICENSE=	TundraWare
LICENSE_NAME=	TundraWare license
LICENSE_FILE=	${WRKSRC}/tdir-license.txt
LICENSE_PERMS=	auto-accept dist-mirror no-dist-sell no-pkg-sell pkg-mirror

USES=		python:run shebangfix
SHEBANG_FILES=	tdir
NO_ARCH=	yes

PLIST_FILES=	bin/tdir \
		man/man1/tdir.1.gz

.include <bsd.port.mk>
