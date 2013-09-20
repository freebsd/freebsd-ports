# Created by: Corey Smith
# $FreeBSD$

PORTNAME=	flowgrep
PORTVERSION=	0.9
CATEGORIES=	net security
MASTER_SITES=	http://www.monkey.org/~jose/software/flowgrep/
DISTNAME=	flowgrep-${PORTVERSION}

MAINTAINER=	corsmith@gmail.com
COMMENT=	TCP stream/UDP/IP payload 'grep' utility

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/nidsmodule.so:${PORTSDIR}/net/pynids

USE_PYTHON=	yes

NO_BUILD=	yes

PLIST_FILES=	sbin/flowgrep

MAN8=	flowgrep.8

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flowgrep.py ${PREFIX}/sbin/flowgrep
	${INSTALL_MAN} ${WRKSRC}/flowgrep.8 ${PREFIX}/man/man8/flowgrep.8

.include <bsd.port.mk>
