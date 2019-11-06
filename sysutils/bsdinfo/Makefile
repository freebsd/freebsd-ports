# Created by: samu <freebsd-ports@samu.pl>
# $FreeBSD$

PORTNAME=	bsdinfo
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GHC

MAINTAINER=	freebsd-ports@samu.pl
COMMENT=	Simple utility to display system-based information

BROKEN=		unfetchable

USE_GITHUB=	yes
GH_ACCOUNT=	samupl
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	X256
OPTIONS_DEFAULT=X256
X256_DESC=	Build the 256 color version
X256_CONFIGURE_ON=	--x256

PLIST_FILES+=	bin/bsdinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdinfo ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
