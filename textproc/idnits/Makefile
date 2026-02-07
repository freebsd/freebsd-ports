PORTNAME=	idnits
PORTVERSION=	2.17.1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Looks for problems in internet draft formatting
WWW=		https://author-tools.ietf.org/idnits \
		https://github.com/ietf-tools/idnits

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/idnits

USE_GITHUB=	yes
GH_ACCOUNT=	ietf-tools

SHEBANG_FILES=	idnits

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/idnits ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
