# $FreeBSD$

PORTNAME=	recog
PORTVERSION=	2.1.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Framework for fingerprinting products

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem
PLIST_FILES=	bin/recog_export \
		bin/recog_match \
		bin/recog_verify

.include <bsd.port.mk>
