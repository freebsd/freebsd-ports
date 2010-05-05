# New ports collection makefile for:   unuran
# Date created:        13 November 2008
# Whom:                bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	unuran
PORTVERSION=	1.7.1
CATEGORIES=	math
MASTER_SITES=	http://statmath.wu-wien.ac.at/unuran/

MAINTAINER=	bf1783@gmail.com
COMMENT=	Universal Non-Uniform RANdom number generators

LIB_DEPENDS=	rngstreams:${PORTSDIR}/math/rngstreams

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-urng-rngstream --with-urng-default=rngstream \
		--enable-info
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	yes
INFO=		unuran
PORTDOCS=	unuran.pdf unuran.txt

post-patch:
	${FIND} -X ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e \
		's/sinclude/#sinclude/g'

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for DD in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${DD} ${DOCSDIR}
.endfor
.endif

.ifdef(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--enable-check-struct --enable-logging

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} check)

fullcheck: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} fullcheck)

.endif

.include <bsd.port.mk>
