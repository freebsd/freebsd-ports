# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jq
PORTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	http://stedolan.github.io/jq/download/source/

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Lightweight and flexible command-line JSON processor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs --docdir="${DOCSDIR}"
USE_CSTD=	gnu99

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

NO_STAGE=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.else
MAKE_ARGS=	docdir=
.endif

.include <bsd.port.post.mk>
