# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	qconfirm
PORTVERSION=	0.14.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://smarden.org/qconfirm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter spam by requesting confirmation from sender

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/package/COPYING

WRKSRC=		${WRKDIR}/mail/${DISTNAME}

ALL_TARGET=	default

OPTIONS_DEFINE=	DOCS

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}" > ${WRKSRC}/src/conf-ld

do-build:
	(cd ${WRKSRC} && package/compile)

do-install:
	(cd ${WRKSRC}/command && ${INSTALL_PROGRAM} * \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/man && ${INSTALL_MAN} *.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/package && ${INSTALL_DATA} CHANGES README \
		${STAGEDIR}${DOCSDIR})

test: build
	(cd ${WRKSRC} && package/check)

.include <bsd.port.mk>
