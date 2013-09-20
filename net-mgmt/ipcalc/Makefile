# Created by: ijliao
# $FreeBSD$

PORTNAME=	ipcalc
PORTVERSION=	0.41
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://jodies.de/ipcalc-archive/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	IP Calculator

PLIST_FILES=	bin/ipcalc
NO_BUILD=	yes
USES=		perl5

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
