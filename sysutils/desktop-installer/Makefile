PORTNAME=	desktop-installer
DISTVERSION=	1.1.1-4
DISTVERSIONSUFFIX=	-gd169ed0
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quickly configure a FreeBSD desktop system
WWW=		https://github.com/outpaddling/desktop-installer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	auto-admin>=0.8.3.27:sysutils/auto-admin

USES=		desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/battery-shutdown.sh ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/FreeBSD/${PORTNAME}.man \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/Common && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/FreeBSD && ${COPYTREE_SHARE} XDM ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
