# Created by: ijliao
# $FreeBSD$

PORTNAME=	cs
PORTVERSION=	0.9.6
CATEGORIES=	misc
MASTER_SITES=	http://njhurst.com/programming/cross-stitch/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross Stitch software

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging

NO_BUILD=	yes

USES=		shebangfix
SHEBANG_FILES=	xs.py
USE_PYTHON_RUN=	yes

PLIST_FILES=	bin/xs

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} xs.py ${STAGEDIR}${PREFIX}/bin/xs)

.include <bsd.port.mk>
