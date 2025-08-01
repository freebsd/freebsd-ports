PORTNAME=	bmd
DISTVERSION=	3.4
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Bhyve Management Daemon
WWW=		https://github.com/yuichiro-naito/bmd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	bhyve runs on amd64 only

RUN_DEPENDS=	bhyve-firmware>0:sysutils/bhyve-firmware \
		grub2-bhyve>0:sysutils/grub2-bhyve

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

.include <bsd.port.mk>
