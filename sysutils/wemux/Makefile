# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	wemux
PORTVERSION=	2.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.c-s.li/ports/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enhances tmux to make multi-user terminal multiplexing easier

LICENSE=	MIT

RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux \
		bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zolrath
GH_TAGNAME=	dfd964792a859ebc24b4210c53c9a0ceb9bb29e6
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-dfd9647

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/wemux ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/wemux.conf.example ${STAGEDIR}${PREFIX}/etc/wemux.conf.example

.include <bsd.port.mk>
