# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdf-redact-tools
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	print
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Securely redact and strip metadata from PDF files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool \
		convert:graphics/ImageMagick6

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

GH_ACCOUNT=	firstlookmedia

.include <bsd.port.mk>
