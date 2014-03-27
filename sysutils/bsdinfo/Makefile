# Created by: samu <s@samu.pl>
# $FreeBSD$

PORTNAME=	bsdinfo
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/samupl/bsdinfo/

MAINTAINER=	s@samu.pl
COMMENT=	Simple utility to display system-based information

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	X256
OPTIONS_DEFAULT=X256
X256_DESC=	Build the 256 color version
X256_CONFIGURE_ON=	--x256

PLIST_FILES+=	bin/bsdinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdinfo ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
