# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jq
PORTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	http://stedolan.github.io/jq/download/source/

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Lightweight and flexible command-line JSON processor

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs --docdir="${DOCSDIR}"
USE_CSTD=	gnu99

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
MAKE_ARGS=	docdir=
.endif

.include <bsd.port.mk>
