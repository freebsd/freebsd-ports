# Created by: fenner@FreeBSD.org
# $FreeBSD$

PORTNAME=	idnits
PORTVERSION=	2.13.00
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/idnits/ \
		LOCAL/sunpoet
EXTRACT_SUFX=	.tgz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Looks for problems in internet draft formatting

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '1 s|^#!/bin/bash|#!${LOCALBASE}/bin/bash|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
