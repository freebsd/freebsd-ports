# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	qconfirm
PORTVERSION=	0.14.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://smarden.org/qconfirm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter spam by requesting confirmation from sender

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/package/COPYING

WRKSRC=		${WRKDIR}/mail/${DISTNAME}

ALL_TARGET=	default

OPTIONS_DEFINE=	DOCS

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	@${ECHO_CMD} "${CC} ${LDFLAGS}" > ${WRKSRC}/src/conf-ld

do-build:
	(cd ${WRKSRC} && package/compile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/package && ${INSTALL_DATA} CHANGES README \
		${STAGEDIR}${DOCSDIR})

do-test:
	# XXX: this dies with bus error; the port may be faulty as well
	cd ${WRKSRC} && package/check

.include <bsd.port.mk>
