# Created by: ijliao
# $FreeBSD$

PORTNAME=	yacas
PORTVERSION=	1.3.3
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	TESTS DOCS
OPTIONS_DEFAULT=TESTS
TESTS_DESC=	Run bundled self-tests after build

USES=		gmake
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

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| /bin/bash| ${LOCALBASE}/bin/bash|' ${WRKSRC}/tests/test-yacas

post-build:
.if ${PORT_OPTIONS:MTESTS}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} check ${MAKE_ARGS})
.endif

.include <bsd.port.mk>
