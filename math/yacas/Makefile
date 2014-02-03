# Created by: ijliao
# $FreeBSD$

PORTNAME=	yacas
PORTVERSION=	1.3.4
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

#USES=		gmake
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-html-doc --with-html-dir=${DOCSDIR}
PORTDOCS=	*
USES+=		perl5
USE_PERL5=	build
.else
CONFIGURE_ARGS+=--disable-html-doc
.endif

post-patch:
#	Can't use USES=shebangfix here, cause the path appears several
#	times in the file.
	@${REINPLACE_CMD} -e 's| /bin/bash| ${LOCALBASE}/bin/bash|g' \
	    ${WRKSRC}/tests/test-yacas

regression-test: build
#	This requires bash. I don't add it as a dependency to the port, as it's
#	not needed for the general use.
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
	    ${MAKEFILE} check ${MAKE_ARGS})

.include <bsd.port.mk>
