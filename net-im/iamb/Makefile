PORTNAME=	iamb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.10
PORTREVISION=	9
CATEGORIES=	net-im

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Matrix client for Vim addicts
WWW=		https://iamb.chat/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build
USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ulyssa

PLIST_FILES=	bin/iamb \
		share/man/man1/iamb.1.gz \
		share/man/man5/iamb.5.gz

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/iamb.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/docs/iamb.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

.include <bsd.port.post.mk>
