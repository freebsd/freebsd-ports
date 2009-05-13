# New ports collection makefile for:   rngstreams
# Date created:        13 November 2008
# Whom:                bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	TestU01
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.iro.umontreal.ca/~simardr/testu01/:0 \
		http://www.iro.umontreal.ca/~lecuyer/myftp/papers/:1
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}:0 testu01.pdf:1
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf2006a@yahoo.com
COMMENT=	Utilities for statistical testing of uniform random number generators

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

USE_ZIP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${PREFIX}/include/${PORTNAME}"
USE_GMAKE=	yes
MAKE_ARGS=	docdir="${DOCSDIR}" exdir="${EXAMPLESDIR}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
CLAGS+=		-fPIC
PLIST_SUB=	PORTNAME="${PORTNAME}"

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -e  '/^SUBDIRS \=/s/ doc / /' ${WRKSRC}/Makefile.in
	@${FIND} -X ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} \
	-e '/^install-data-am\: /s/install-docDATA//'
.endif
.ifdef(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e  '/^SUBDIRS \=/s/ examples / /' ${WRKSRC}/Makefile.in
.endif

.ifndef(NOPORTDOCS)
post-install:
	@${INSTALL_DATA} ${DISTDIR}/testu01.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
