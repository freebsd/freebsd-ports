# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	biabam
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Command-line attachment mailer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

NO_BUILD=	yes
PLIST_FILES=	bin/biabam
USES=		shebangfix
SHEBANG_FILES=${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/biabam ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
