# Created by: adamw
# $FreeBSD$

PORTNAME=	geoipupdate
PORTVERSION=	4.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fetch the latest copies of the GeoIP2 databases

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

RUN_DEPENDS=	ca_root_nss>=3:security/ca_root_nss

USES=		gmake go:modules,no_targets
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

MAKE_ENV+=	${GO_ENV} \
		CONFFILE=${PREFIX}/etc/GeoIP.conf \
		DATADIR=${PREFIX}/share/GeoIP \
		VERSION=${DISTVERSIONFULL}

GH_TUPLE=	\
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-check:check:038fdea0a05b:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gofrs:flock:v0.8.0:gofrs_flock/vendor/github.com/gofrs/flock \
		golang:sys:119d4633e4d1:golang_sys/vendor/golang.org/x/sys \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	lowdown:textproc/lowdown
MANPAGES_PLIST_FILES=	man/man1/geoipupdate.1.gz \
			man/man5/GeoIP.conf.5.gz

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
	${INSTALL_MAN} ${WRKSRC}/build/geoipupdate.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/GeoIP.conf.5  ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
