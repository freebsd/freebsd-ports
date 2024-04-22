PORTNAME=	iocell
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Feature rich Jail containers manager (iocage fork)
WWW=		https://github.com/bartekrutkowski/iocell

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	uclcmd:devel/uclcmd

USE_GITHUB=	yes
GH_ACCOUNT=	bartekrutkowski

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|amd64|${MACHINE}|g" ${WRKSRC}/lib/ioc-*
	@${REINPLACE_CMD} -e "s|/usr/local/lib/iocell|${PREFIX}/lib/iocell|g" ${WRKSRC}/iocell

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/iocell

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/iocell ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/iocell ${STAGEDIR}${PREFIX}/sbin
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/iocell)
	${INSTALL_MAN} ${WRKSRC}/iocell.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
