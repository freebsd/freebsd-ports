# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	asciidoc
PORTVERSION=	9.0.4
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/asciidoc/asciidoc-py3/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text document format for writing short documents and man pages

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl

USES=		gmake gnome python:3.5+ shebangfix
USE_GNOME=	libxml2 libxslt

GNU_CONFIGURE=	yes
NO_ARCH=	yes

SHEBANG_GLOB=	*.py

post-patch:
	@${REINPLACE_CMD} -e 's|python3 |${PYTHON_CMD} |' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/a2x.py
	@${FIND} ${WRKSRC} -name '*.conf' | ${XARGS} -I % ${LN} % %.sample

post-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/asciidocapi.py ${STAGEDIR}${PYTHON_SITELIBDIR}/

.include <bsd.port.mk>
