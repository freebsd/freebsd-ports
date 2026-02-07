PORTNAME=	cs
PORTVERSION=	0.9.6
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://njhurst.com/programming/cross-stitch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross Stitch software
WWW=		http://njhurst.org/programming/cross-stitch/

LICENSE=	GPLv2+

RUN_DEPENDS=	${PY_PILLOW}

NO_BUILD=	yes

USES=		python:run shebangfix tar:tgz
SHEBANG_FILES=	xs.py

PLIST_FILES=	bin/xs

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} xs.py ${STAGEDIR}${PREFIX}/bin/xs)

.include <bsd.port.mk>
