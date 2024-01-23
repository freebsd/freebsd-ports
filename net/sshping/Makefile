PORTNAME=	sshping
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	SSH-based ping to measure character echo latency and bandwidth
WWW=		https://github.com/spook/sshping/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh.so:security/libssh

USES=		cmake localbase:ldflags perl5
USE_GITHUB=	yes
GH_ACCOUNT=	spook
USE_PERL5=	build

PLIST_FILES=	bin/sshping \
		share/man/man8/sshping.8.gz

.include <bsd.port.mk>
