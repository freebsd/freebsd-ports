PORTNAME=	gsocket
PORTVERSION=	1.4.28
CATEGORIES=	net
MASTER_SITES=	https://github.com/hackerschoice/gsocket/releases/download/v${PORTVERSION}/

MAINTAINER=	arr@watson.org
COMMENT=	Allows two users behind NAT/Firewall to establish a TCP connection

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		shebangfix ssl

SHEBANG_FILES=  tools/blitz \
		tools/gsocket \
		tools/gs_funcs \
		tools/gs-mount \
		tools/gs-sftp

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
