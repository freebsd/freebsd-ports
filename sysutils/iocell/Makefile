PORTNAME=	iocell
PORTVERSION=	2.1.2
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/pull/
PATCHFILES+=	37.patch:-p1 # https://github.com/bartekrutkowski/iocell/pull/37

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Feature rich Jail containers manager (iocage fork)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	uclcmd:devel/uclcmd

CONFLICTS=	iocage

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
	${INSTALL_MAN} ${WRKSRC}/iocell.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
