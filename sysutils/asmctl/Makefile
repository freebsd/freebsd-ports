PORTNAME=	asmctl
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Apple System Management Controller
WWW=		https://github.com/yuichiro-naito/asmctl

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/devd/asmctl.conf \
		${STAGEDIR}${PREFIX}/etc/devd/asmctl.conf.sample

.include <bsd.port.mk>
