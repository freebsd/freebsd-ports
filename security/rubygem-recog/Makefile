PORTNAME=	recog
PORTVERSION=	3.1.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Framework for fingerprinting products
WWW=		https://github.com/rapid7/recog

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes
PLIST_FILES=	bin/recog_match

.include <bsd.port.mk>
