PORTNAME=	bmd
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Bhyve Management Daemon
WWW=		https://github.com/yuichiro-naito/bmd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# Because bhyve runs on amd64 only.
ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	bhyve-firmware>0:sysutils/bhyve-firmware \
		grub2-bhyve>0:sysutils/grub2-bhyve

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

.include <bsd.port.mk>
