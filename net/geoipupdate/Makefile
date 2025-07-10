PORTNAME=	geoipupdate
PORTVERSION=	7.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fetch the latest copies of the GeoIP2 databases
WWW=		https://github.com/maxmind/geoipupdate

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		gmake go:modules,no_targets
GO_MODULE=	github.com/maxmind/geoipupdate/v7

MAKE_ENV+=	${GO_ENV} \
		CONFFILE=${PREFIX}/etc/GeoIP.conf \
		DATADIR=${PREFIX}/share/GeoIP \
		VERSION=${DISTVERSIONFULL}

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	lowdown:textproc/lowdown
MANPAGES_PLIST_FILES=	share/man/man1/geoipupdate.1.gz \
			share/man/man5/GeoIP.conf.5.gz

PLIST_FILES=	bin/geoipupdate \
		'@sample etc/GeoIP.conf.sample' \
		'@dir share/GeoIP'
PORTDOCS=	GeoIP.conf.md geoipupdate.md
SUB_FILES=	pkg-message

do-build-MANPAGES-on:
	# lowdown generates everything as section 7
	{ ${PRINTF} "title: geoipupdate\n\n" && ${CAT} ${WRKSRC}/doc/geoipupdate.md; } \
		| ${LOCALBASE}/bin/lowdown -s -Tman \
		| ${SED} -e '1s/7/1/' > ${WRKSRC}/build/geoipupdate.1
	{ ${PRINTF} "title: GeoIP.conf\n\n" && ${CAT} ${WRKSRC}/doc/GeoIP.conf.md; } \
		| ${LOCALBASE}/bin/lowdown -s -Tman \
		| ${SED} -e '1s/7/5/' > ${WRKSRC}/build/GeoIP.conf.5

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/GeoIP
	${INSTALL_PROGRAM} ${WRKSRC}/build/geoipupdate ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/GeoIP.conf ${STAGEDIR}${PREFIX}/etc/GeoIP.conf.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/build/geoipupdate.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/GeoIP.conf.5  ${STAGEDIR}${PREFIX}/share/man/man5

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} test ${GO_TESTFLAGS} ./...

.include <bsd.port.mk>
