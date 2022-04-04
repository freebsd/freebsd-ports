PORTNAME=	apertium-eng
PORTVERSION=	0.1.0.20220212
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Apertium monolingual language package for English

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	apertium>0:textproc/apertium
LIB_DEPENDS=	libcg3.so:textproc/cg3

USES=		autoreconf gmake pathfix pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	apertium
GH_TAGNAME=	b230738

GNU_CONFIGURE=	yes

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g ; \
		s|^pkgconfigdir.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig| ' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
