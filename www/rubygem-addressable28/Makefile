PORTNAME=	addressable
PORTVERSION=	2.8.10
PORTREVISION=	1
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	28

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Replacement for the URI implementation
WWW=		https://github.com/sporkmonger/addressable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	This version has a vulnerability (CVE-2026-35611)
EXPIRATION_DATE=2026-12-11

RUN_DEPENDS=	rubygem-public_suffix>=2.0.2<8.0:dns/rubygem-public_suffix

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	addressable_project

.include <bsd.port.mk>
