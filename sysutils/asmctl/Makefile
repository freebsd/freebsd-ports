PORTNAME=	asmctl
DISTVERSION=	2.2
CATEGORIES=	sysutils

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Apple System Management Controller
WWW=		https://github.com/yuichiro-naito/asmctl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	yuichiro-naito

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/devd/asmctl.conf \
		${STAGEDIR}${PREFIX}/etc/devd/asmctl.conf.sample

.include <bsd.port.mk>
