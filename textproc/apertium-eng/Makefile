PORTNAME=	apertium-eng
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0.20250406
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Apertium monolingual language package for English
WWW=		https://www.apertium.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_15_armv7=	segmentation fault

BUILD_DEPENDS=	apertium>0:textproc/apertium
LIB_DEPENDS=	libcg3.so:textproc/cg3

USES=		autoreconf gmake pathfix pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	apertium
GH_TAGNAME=	8e62ef0

GNU_CONFIGURE=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
