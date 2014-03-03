# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	byobu
PORTVERSION=	5.73
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	gslin@gslin.org
COMMENT=	Profile and configuration utilities for GNU Screen

RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	BASH_DEVEL
BASH_DEVEL_DESC=Use bash-devel instead of bash
BASH_DEVEL_RUN_DEPENDS=		bash:${PORTSDIR}/shells/bash-devel
BASH_DEVEL_RUN_DEPENDS_OFF=	bash:${PORTSDIR}/shells/bash

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} \
			-e "s@/bin/bash@${LOCALBASE}/bin/bash@" \
			-e "s@/usr/bin/python@${PYTHON_CMD}@"

.include <bsd.port.mk>
