PORTNAME=	gsocket
PORTVERSION=	1.4.28
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/hackerschoice/gsocket/releases/download/v${PORTVERSION}/

MAINTAINER=	arr@watson.org
COMMENT=	Connect two users behind NAT/firewall via TCP/IP

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix ssl

SHEBANG_FILES=	tools/blitz \
		tools/gsocket \
		tools/gs_funcs \
		tools/gs-mount \
		tools/gs-sftp

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
