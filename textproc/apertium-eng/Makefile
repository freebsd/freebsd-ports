PORTNAME=	apertium-eng
PORTVERSION=	0.1.0.20220212
PORTREVISION=	1
DISTVERSIONPREFIX=	v
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
GH_TAGNAME=	b230738

GNU_CONFIGURE=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
