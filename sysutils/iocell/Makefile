# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iocell
PORTVERSION=	2.1.2
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Feature rich Jail containers manager (iocage fork)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	uclcmd:devel/uclcmd

CONFLICTS=	iocage-*

USE_GITHUB=	yes
GH_ACCOUNT=	bartekrutkowski

NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/lib/iocell|${PREFIX}/lib/iocell|g" ${WRKSRC}/iocell

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/iocell

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/iocell ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/iocell ${STAGEDIR}${PREFIX}/sbin
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/iocell)
	${INSTALL_MAN} ${WRKSRC}/iocell.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
