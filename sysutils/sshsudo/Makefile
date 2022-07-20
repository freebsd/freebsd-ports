PORTNAME=	sshsudo
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	gaod@hychen.org
COMMENT=	Bash script to run sudo command on multiple remote computers

LICENSE=	GPLv3

RUN_DEPENDS=	bash:shells/bash \
		sshpass>=0:security/sshpass

USE_GITHUB=	yes
GH_ACCOUNT=	gaod

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/sshsudo

post-patch:
	${SED} -e "s,/bin/bash,${LOCALBASE}/bin/bash," -e "s,mktemp,mktemp -t sshsudo," \
	<${WRKSRC}/${PORTNAME}-${PORTVERSION}/${PORTNAME} >${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
