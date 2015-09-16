# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jq
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	http://stedolan.github.io/jq/download/source/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Lightweight and flexible command-line JSON processor

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs --docdir="${DOCSDIR}"
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
USES=		libtool

PLIST_FILES=	bin/${PORTNAME} \
		include/jq.h include/jv.h \
		lib/libjq.a lib/libjq.so lib/libjq.so.1 lib/libjq.so.1.0.4 \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

DOCS_MAKE_ARGS_OFF=	docdir=

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libjq.so.1.0.4

.include <bsd.port.mk>
