PORTNAME=	xdrawchem
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Two-dimensional molecule drawing program
WWW=		https://sourceforge.net/projects/xdrawchem/ \
		https://github.com/bryanherger/xdrawchem

LICENSE=	GPLv3

LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase:ldflags pkgconfig qt:6
USE_QT=		base svg tools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	bryanherger

WRKSRC_SUBDIR=	xdrawchem

LDFLAGS+=	-lexecinfo

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
