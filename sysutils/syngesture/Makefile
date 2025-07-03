PORTNAME=	syngesture
DISTVERSION=	1.0.1
PORTREVISION=	17
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Swipes and gestures with the MT multitouch protocol
WWW=		https://github.com/mqudsi/syngesture

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	evtest:x11/evtest

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	mqudsi

CARGO_CRATES=	aho-corasick-0.7.18 \
		cfg-if-1.0.0 \
		log-0.4.17 \
		memchr-2.5.0 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		serde-1.0.143 \
		serde_derive-1.0.143 \
		serde_repr-0.1.9 \
		syn-1.0.99 \
		toml-0.5.9 \
		unicode-ident-1.0.3

PLIST_FILES=	bin/${PORTNAME}s

.include <bsd.port.mk>
