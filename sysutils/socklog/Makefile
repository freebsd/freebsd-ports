PORTNAME=	socklog
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://smarden.org/socklog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and secure replacement for syslogd
WWW=		http://smarden.org/socklog/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/package/COPYING

RUN_DEPENDS=	${LOCALBASE}/sbin/chpst:sysutils/runit

WRKSRC=		${WRKDIR}/admin/${DISTNAME}
ALL_TARGET=	default

TEXTDOCS=	CHANGES README
HTMLDOCS=	*.html
PORTDOCS=	${TEXTDOCS} ${HTMLDOCS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${CC} -s ${LDFLAGS}" > ${WRKSRC}/src/conf-ld

do-build:
	cd ${WRKSRC} && package/compile
	@${ECHO_MSG} "Type 'make test' to run self-tests"

test:
	cd ${WRKSRC} && package/check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${STAGEDIR}${PREFIX}/share/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${TEXTDOCS:S,^,${WRKSRC}/package/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${HTMLDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
