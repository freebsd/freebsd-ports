PORTNAME=	pkg-graph
DISTVERSION=	g20180614
PORTREVISION=	33
CATEGORIES=	ports-mgmt

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Graphviz generator for pkg
WWW=		https://github.com/neosmart/pkg-graph

LICENSE=	BSD2CLAUSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	neosmart
GH_TAGNAME=	3b16898

CARGO_CRATES=	dtoa-0.4.2 \
		itoa-0.4.1 \
		proc-macro2-0.4.6 \
		quote-0.6.3 \
		serde-1.0.66 \
		serde_derive-1.0.66 \
		serde_json-1.0.20 \
		syn-0.14.2 \
		unicode-xid-0.1.0

PLIST_FILES=	bin/pkg-graph

.include <bsd.port.mk>
