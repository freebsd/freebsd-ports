PORTNAME=	dockerbox
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
CATEGORIES=	sysutils

MAINTAINER=	leafoliage@FreeBSD.org
COMMENT=	Virtualized Docker daemon
WWW=		https://github.com/leafoliage/freebsd-dockerbox

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	e2fsprogs>0:filesystems/e2fsprogs \
		grub2-bhyve>0:sysutils/grub2-bhyve \
		docker-cli>0:sysutils/docker-cli

USE_GITHUB=	yes
GH_ACCOUNT=	leafoliage
GH_PROJECT=	freebsd-dockerbox

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/dockerbox ${STAGEDIR}${PREFIX}/sbin/dockerbox
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/dockerbox.conf ${STAGEDIR}${ETCDIR}/dockerbox.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/dockerbox ${STAGEDIR}${PREFIX}/etc/rc.d/dockerbox

.include <bsd.port.mk>
