# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mimedetect
DISTVERSION=	6.x-1.3
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for Consistent Server Side Mime Detection

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		drupal:6,module

MODULE_FILES=	magic magic.mgc magic.mime \
		mimedetect.info mimedetect.install mimedetect.module
DOC_FILES=	LICENSE.txt README.txt
OPTIONS_DEFINE=	DOCS
NO_ARCH=	yes

.include <bsd.port.mk>
