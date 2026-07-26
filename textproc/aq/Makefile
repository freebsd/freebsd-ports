PORTNAME=	aq
DISTVERSION=	0.5.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extend jq for any data format
WWW=		https://github.com/rossmacarthur/aq

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

RUN_DEPENDS=	jq:textproc/jq

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	rossmacarthur

CARGO_CRATES=	anyhow-1.0.103 \
		equivalent-1.0.2 \
		hashbrown-0.17.1 \
		indexmap-2.14.0 \
		itoa-1.0.18 \
		libyaml-rs-0.3.0 \
		memchr-2.8.2 \
		proc-macro2-1.0.106 \
		quote-1.0.46 \
		ryu-1.0.23 \
		serde-1.0.228 \
		serde-transcode-1.1.1 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.150 \
		serde_spanned-1.1.1 \
		syn-2.0.118 \
		toml-1.1.2+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_parser-1.1.2+spec-1.1.0 \
		toml_writer-1.1.1+spec-1.1.0 \
		unicode-ident-1.0.24 \
		winnow-1.0.3 \
		yaml_serde-0.10.4 \
		zmij-1.0.21

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
