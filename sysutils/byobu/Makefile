# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	byobu
PORTVERSION=	5.73
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Profile and configuration utilities for GNU Screen

RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen \
				bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} \
			-e "s@/bin/bash@${LOCALBASE}/bin/bash@" \
			-e "s@/usr/bin/python@${PYTHON_CMD}@"

.include <bsd.port.mk>
