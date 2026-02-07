PORTNAME=	blahtexml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TeX to MathML converter designed with MediaWiki in mind
WWW=		http://gva.noekeon.org/blahtexml/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		gmake iconv localbase
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	gvanas

MAKEFILE=	makefile
ALL_TARGET=	blahtexml-linux

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
