PORTNAME=	recog
PORTVERSION=	2.3.23
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Framework for fingerprinting products
WWW=		https://github.com/rapid7/recog

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri

USES=		gem python:env shebangfix

NO_ARCH=	yes
SHEBANG_FILES=	update_cpes.py .vscode/bin/monitor-recog-fingerprints.sh
PLIST_FILES=	bin/recog_cleanup \
		bin/recog_export \
		bin/recog_match \
		bin/recog_standardize \
		bin/recog_verify

.include <bsd.port.mk>
