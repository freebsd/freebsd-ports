# $FreeBSD$

PORTNAME=	recog
PORTVERSION=	2.1.46
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Framework for fingerprinting products

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri

NO_ARCH=	yes
USES=		gem python:env shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	update_cpes.py
PLIST_FILES=	bin/recog_export \
		bin/recog_match \
		bin/recog_verify

.include <bsd.port.mk>
