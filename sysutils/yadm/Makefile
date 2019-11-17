# $FreeBSD$

PORTNAME=	yadm
PORTVERSION=	2.0.1
CATEGORIES=	sysutils

MAINTAINER=	alex@xanderio.de
COMMENT=	Yet Another Dotfiles Manager

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git \
		bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	TheLocehiliosan

PLIST_FILES=	bin/yadm \
		man/man1/yadm.1.gz

do-install:
	@${MKDIR} ${STAGEDIR}
	${INSTALL_MAN} ${WRKSRC}/yadm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/yadm ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
