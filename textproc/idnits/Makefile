PORTNAME=	idnits
PORTVERSION=	2.17.00
CATEGORIES=	textproc
MASTER_SITES=	https://tools.ietf.org/tools/idnits/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Looks for problems in internet draft formatting

LICENSE=	GPLv2+

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix tar:tgz

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/idnits

SHEBANG_FILES=	idnits

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/idnits ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
