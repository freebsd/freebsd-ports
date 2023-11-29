PORTNAME=	f-upgrade
DISTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	freebsd@moov.de
COMMENT=	Unattended FreeBSD operating system updates
WWW=		https://github.com/fraenki/f-upgrade

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	fraenki

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/rc.d/f_upgrade.in

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/f_upgrade.in ${STAGEDIR}${PREFIX}/etc/rc.d/f_upgrade
	(cd ${WRKSRC} && ${COPYTREE_SHARE} libdata ${STAGEDIR}${PREFIX})
	(cd ${WRKSRC}/etc && ${COPYTREE_SHARE} ${PORTNAME}.hook.d ${STAGEDIR}${PREFIX}/etc)
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf.dist ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
