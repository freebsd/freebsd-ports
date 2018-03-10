# Created by: Yuichiro NAITO <naito.yuichiro@gmail.com>
# $FreeBSD$

PORTNAME=	asmctl
PORTVERSION=	1.6
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Apple System Management Controller

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/devd/asmctl.conf \
		${STAGEDIR}${PREFIX}/etc/devd/asmctl.conf.sample

.include <bsd.port.mk>
