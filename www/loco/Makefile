PORTNAME=	loco
DISTVERSION=	g20240225
PORTREVISION=	4
CATEGORIES=	www devel
PKGNAMESUFFIX=	-web-framework

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web framework for Rust for side-projects and startups
WWW=		https://loco.rs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	loco-rs
GH_TAGNAME=	9f4f444

WRKSRC_SUBDIR=	${PORTNAME}-cli

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <Makefile.crates>
.include <bsd.port.mk>
