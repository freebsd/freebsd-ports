# Created by: Slaven Rezic <slaven@rezic.de>
# $FreeBSD$

PORTNAME=	lesspipe
PORTVERSION=	1.83
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	slaven@rezic.de
COMMENT=	Preprocessor for less

LICENSE=	GPLv2

MY_DEPENDS=	bash:shells/bash
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5

NO_BUILD=	yes
NO_ARCH=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--yes --prefix=${PREFIX}

PLIST_FILES=	bin/lesspipe.sh bin/code2color man/man1/lesspipe.1.gz

SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2color  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lesspipe.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}    ${WRKSRC}/lesspipe.1  ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
