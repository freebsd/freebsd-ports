PORTNAME=	qconfirm
PORTVERSION=	0.14.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://smarden.org/qconfirm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter spam by requesting confirmation from sender
WWW=		http://smarden.org/qconfirm/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/package/COPYING

WRKSRC=		${WRKDIR}/mail/${DISTNAME}

ALL_TARGET=	default

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	@${ECHO_CMD} "${CC} ${LDFLAGS}" > ${WRKSRC}/src/conf-ld

do-build:
	(cd ${WRKSRC} && package/compile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/package && ${INSTALL_DATA} CHANGES README \
		${STAGEDIR}${DOCSDIR})

do-test:
	# XXX: this dies with bus error; the port may be faulty as well
	cd ${WRKSRC} && package/check

.include <bsd.port.mk>
