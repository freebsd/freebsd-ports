# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	wemux
PORTVERSION=	3.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Enhances tmux to make multi-user terminal multiplexing easier

LICENSE=	MIT

RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux \
		bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zolrath
GH_TAGNAME=	971f8c375263f9dd8853f676e3331782c4fbdfdc
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-971f8c3

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/wemux ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/wemux.conf.example ${STAGEDIR}${PREFIX}/etc/wemux.conf.example

.include <bsd.port.mk>
