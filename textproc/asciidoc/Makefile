# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	asciidoc
PORTVERSION=	8.6.10
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text document format for writing short documents and man pages

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
NO_ARCH=	yes
USE_GNOME=	libxml2 libxslt
USES=		autoreconf gmake gnome python:2.7 shebangfix

USE_GITHUB=	yes

SHEBANG_GLOB=	*.py
SHEBANG_LANG=	python2
python2_CMD=	${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALL_PROG/ s|INSTALL_PROGRAM|INSTALL_SCRIPT|; s|\.conf|&.sample|; s|python\( a2x.py\)|${PYTHON_CMD}\1|' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name '*.conf' | ${XARGS} -I % ${LN} % %.sample

post-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/asciidocapi.py ${STAGEDIR}${PYTHON_SITELIBDIR}/

.include <bsd.port.mk>
