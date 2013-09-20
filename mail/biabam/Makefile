# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	biabam
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A command-line attachment mailer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
PLIST_FILES=	bin/biabam

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '1s|\(#!\)\(/bin/bash\)|\1${LOCALBASE}\2|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/biabam ${PREFIX}/bin

.include <bsd.port.mk>
