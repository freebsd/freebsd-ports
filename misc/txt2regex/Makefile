# ex:ts=8
# New ports collection makefile for:	txt2regex
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	txt2regex
PORTVERSION=	0.8
CATEGORIES=	misc
MASTER_SITES=	http://txt2regex.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Regular Expression "wizard"

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_REINPLACE=	yes
NO_BUILD=	yes

MAN1=		txt2regex.1
PLIST_FILES=	bin/txt2regex

post-patch:
	@${REINPLACE_CMD} -e \
		"s,/bin/bash,${LOCALBASE}/bin/bash,g" ${WRKSRC}/${DISTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.sh ${PREFIX}/bin/txt2regex
	${INSTALL_MAN} ${WRKSRC}/txt2regex.man ${MANPREFIX}/man/man1/txt2regex.1

.include <bsd.port.mk>
