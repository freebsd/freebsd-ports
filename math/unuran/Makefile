# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	unuran
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://statmath.wu-wien.ac.at/unuran/ \
		LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Universal Non-Uniform RANdom number generators

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librngstreams.so:math/rngstreams

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-urng-rngstream --with-urng-default=rngstream \
		--enable-info
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	MAKE="${MAKE_CMD}"

USE_LDCONFIG=	yes
INFO=		unuran
PORTDOCS=	unuran.pdf unuran.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/UNURANFULLCHECK=true make check/s/make/${MAKE_CMD}/' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DD in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${DD} ${STAGEDIR}${DOCSDIR}
.endfor

.ifdef(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--enable-check-struct --enable-logging

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check)

fullcheck: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} fullcheck)

.endif

.include <bsd.port.mk>
