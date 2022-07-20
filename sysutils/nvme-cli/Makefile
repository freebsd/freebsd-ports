PORTNAME=	nvme-cli
PORTVERSION=	1.8.1
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Port of Linux nvme cli utility

LICENSE=	GPLv2

# only tested on amd64, all other archs are no-go until we're sure amd64 works.
# And there's plenty in amd64 that compiles, but won't run (eg using /sys/, etc)
ONLY_FOR_ARCHS=	amd64

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	c92d871

PLIST_FILES=	sbin/nvme

.include <bsd.port.mk>
