PORTNAME=	loco
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.3
PORTREVISION=	1
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

WRKSRC_SUBDIR=	${PORTNAME}-cli

PLIST_FILES=	bin/${PORTNAME}

.include <Makefile.crates>
.include <bsd.port.mk>
