PORTNAME=	keepass-diff
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	CLI-tool to diff two Keepass (.kdbx) files
WWW=		https://keepass-diff.narigo.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Narigo

PLIST_FILES=	bin/keepass-diff

OPTIONS_DEFINE=	NATIVE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNATIVE}
RUSTFLAGS=	-C target-cpu=native
.endif

.include <bsd.port.mk>
