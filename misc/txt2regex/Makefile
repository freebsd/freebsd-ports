# Created by: ijliao
# $FreeBSD$

PORTNAME=	txt2regex
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://txt2regex.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Regular Expression "wizard"

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
NO_BUILD=	yes

MAN1=		txt2regex.1
PLIST_FILES=	bin/txt2regex

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		"s,/bin/bash,${LOCALBASE}/bin/bash,g" ${WRKSRC}/${DISTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.sh ${PREFIX}/bin/txt2regex
	${INSTALL_MAN} ${WRKSRC}/txt2regex.man ${MANPREFIX}/man/man1/txt2regex.1

.include <bsd.port.mk>
