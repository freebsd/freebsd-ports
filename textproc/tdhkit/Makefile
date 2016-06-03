# Created by: corky1951@comcast.net
# $FreeBSD$

PORTNAME=	tdhkit
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://quisp.sourceforge.net/${PORTNAME}/
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//1}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of programs for working with tabular ASCII data

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2+

OPTIONS_DEFINE=	CHRON DOCS
OPTIONS_SUB=	yes
CHRON_DESC=	Install libchron

BUILD_WRKSRC=	${WRKSRC}/src

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =|CFLAGS +=|' \
		${WRKSRC}/libsrc/Makefile
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =|CFLAGS +=| ; \
		 s|^CC =|CC ?=| ; \
		 /^all:/s|recsel fldsel|recsel fldmap fldsel|' \
		${BUILD_WRKSRC}/Makefile

pre-build:
	@(cd ${WRKSRC}/libsrc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} -j${MAKE_JOBS_NUMBER} \
		${MAKE_ARGS} default libchron)

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} * \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} libchron.a \
		${STAGEDIR}${PREFIX}/lib)
	(cd ${WRKSRC}/man/mantdh && ${INSTALL_MAN} *.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1)
	(cd ${WRKSRC}/man/mantdh && ${INSTALL_MAN} *.3 \
		${STAGEDIR}${MAN3PREFIX}/man/man3)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/man/html && ${INSTALL_DATA} * \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
