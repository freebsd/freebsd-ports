# Created by: ijliao
# $FreeBSD$

PORTNAME=	yacas
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS

DOCS_USES=		perl5
DOCS_USE=		perl5=build
DOCS_CONFIGURE_ENABLE=	html-doc

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc"
CPPFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|"GNU strip"|"strip"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/src/yacasmain.cpp
#	Can't use USES=shebangfix here, cause the path appears several
#	times in the file.
	@${REINPLACE_CMD} -e \
		's| /bin/bash| ${LOCALBASE}/bin/bash|g' \
		${WRKSRC}/tests/test-yacas

regression-test: build
#	This requires bash. I don't add it as a dependency to the port, as
#	it's not needed for the general use.
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} check)

.include <bsd.port.post.mk>
