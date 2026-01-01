PORTNAME=	bvm
DISTVERSION=	1.4.0
CATEGORIES=	sysutils

MAINTAINER=	bigdragonsoft@gmail.com
COMMENT=	Bhyve VM Manager
WWW=		https://github.com/bigdragonsoft/bvm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Bhyve VM Manager is required to be built on a 64bit machine

RUN_DEPENDS=	bhyve-firmware>0:sysutils/bhyve-firmware \
		grub-bhyve:sysutils/grub2-bhyve \
		swtpm:sysutils/swtpm \
		tmux:sysutils/tmux

USE_GITHUB=	yes
GH_ACCOUNT=	bigdragonsoft

BUILD_WRKSRC=	${WRKSRC}/src

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/templates
.for _CONF in bvm.conf dhcp.conf nat.conf switch.conf \
	templates/freebsd.conf templates/linux.conf templates/windows.conf
	${INSTALL_DATA} ${WRKSRC}/conf/${_CONF} ${STAGEDIR}${ETCDIR}/${_CONF}.sample
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/conf/bvmd ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_PROGRAM} ${WRKSRC}/src/bvm \
		${WRKSRC}/src/bvmb \
		${WRKSRC}/src/bvmdhcp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bvm.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
