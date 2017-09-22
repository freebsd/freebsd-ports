# $FreeBSD$

PORTNAME=	rouge
PORTVERSION=	1.11.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, easy-to-extend drop-in replacement for pygments

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use textproc/rubygem-rouge instead
EXPIRATION_DATE=2017-10-31

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/rougify${PKGNAMESUFFIX}

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/rougify ${STAGEDIR}${PREFIX}/bin/rougify${PKGNAMESUFFIX}

.include <bsd.port.mk>
