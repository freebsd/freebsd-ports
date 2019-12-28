# Created by: adamw
# $FreeBSD$

PORTNAME=	geoipupdate
PORTVERSION=	4.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fetch the latest copies of the GeoIP2 databases

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

RUN_DEPENDS=	ca_root_nss>=3:security/ca_root_nss

USES=		gmake go:no_targets
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

MAKE_ENV+=	GOPATH=${WRKSRC} \
		CONFFILE=${PREFIX}/etc/GeoIP.conf \
		DATADIR=${PREFIX}/share/GeoIP

GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
# Not needed: go-spew, pretty, testify
GH_TUPLE=	gofrs:flock:v0.7.1:flock/src/github.com/gofrs/flock \
		pkg:errors:v0.8.1:pkg/src/github.com/pkg/errors \
		spf13:pflag:v1.0.5:pflag/src/github.com/spf13/pflag

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	lowdown:textproc/lowdown
MANPAGES_PLIST_FILES=	man/man1/geoipupdate.1.gz \
			man/man5/GeoIP.conf.5.gz

PLIST_FILES=	bin/geoipupdate \
		'@sample etc/GeoIP.conf.sample' \
		'@dir share/GeoIP'
PORTDOCS=	GeoIP.conf.md geoipupdate.md

post-extract:
	${RM} ${WRKSRC}/go.mod

do-build-MANPAGES-on:
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
	${INSTALL_MAN} ${WRKSRC}/build/geoipupdate.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/GeoIP.conf.5  ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
