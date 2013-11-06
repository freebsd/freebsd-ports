# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-mpfr
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Multiprecision floats for Pure

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

MAKE_ARGS+=	libdir="${PREFIX}/lib"

USES=		pkgconfig pure

PLIST_FILES=	lib/pure/mpfr.pure \
		lib/pure/mpfr.so

NO_STAGE=	yes

PORTDOCS=	README

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
