PORTNAME=	gurk-rs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	4
CATEGORIES=	net-im

MAINTAINER=	bsd@orsolic.org
COMMENT=	Signal Messenger client for terminal
WWW=		https://github.com/boxdot/gurk-rs

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE-AGPL-3.0

BUILD_DEPENDS=	gmake:devel/gmake \
		protoc:devel/protobuf
LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher

USES=		cargo perl5 ssl
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	boxdot

PLIST_FILES=	bin/gurk \
		${DATADIR}/README.md

.include <bsd.port.pre.mk>

# avoid address space exhaustion on armv7
.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
.endif

post-patch:
	${REINPLACE_CMD} -e s,%%WRKDIR%%,${WRKDIR}, ${WRKSRC}/Cargo.toml

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
