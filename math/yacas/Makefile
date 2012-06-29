# ex:ts=8
# New ports collection makefile for:	yacas
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yacas
PORTVERSION=	1.3.2
CATEGORIES=	math
MASTER_SITES=	http://yacas.sourceforge.net/backups/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	TESTS DOCS
OPTIONS_DEFAULT=	TESTS
TESTS_DESC=	Run bundled self-tests after build

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-html-doc --with-html-dir=${DOCSDIR}
.else
CONFIGURE_ARGS+=	--disable-html-doc
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
