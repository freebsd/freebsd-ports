PORTNAME=	colly
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Elegant scraper and crawler framework for Golang
WWW=		https://go-colly.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gocolly
GH_TUPLE=	\
		PuerkitoBio:goquery:v1.10.2:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		andybalholm:cascadia:v1.3.3:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		antchfx:htmlquery:v1.3.4:antchfx_htmlquery/vendor/github.com/antchfx/htmlquery \
		antchfx:xmlquery:v1.4.4:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.3.3:antchfx_xpath/vendor/github.com/antchfx/xpath \
		bits-and-blooms:bitset:v1.22.0:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gocolly:colly:v1.2.0:gocolly_colly/vendor/github.com/gocolly/colly \
		golang:appengine:v1.6.8:golang_appengine/vendor/google.golang.org/appengine \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.37.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:text:v0.23.0:golang_text/vendor/golang.org/x/text \
		jawher:mow.cli:v1.1.0:jawher_mow_cli/vendor/github.com/jawher/mow.cli \
		kennygrant:sanitize:v1.2.4:kennygrant_sanitize/vendor/github.com/kennygrant/sanitize \
		nlnwa:whatwg-url:v0.6.1:nlnwa_whatwg_url/vendor/github.com/nlnwa/whatwg-url \
		protocolbuffers:protobuf-go:v1.36.6:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		saintfish:chardet:5e3ef4b5456d:saintfish_chardet/vendor/github.com/saintfish/chardet \
		temoto:robotstxt:v1.1.2:temoto_robotstxt/vendor/github.com/temoto/robotstxt
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME} \
		${EXAMPLES_INSTALLED:S/^/.\/_examples\//}

PLIST_FILES=	bin/${PORTNAME} \
		${EXAMPLES_INSTALLED:S/^/bin\/${PORTNAME}-/}

# many examples of this sraping framework are interesting in themselves, and therefore are installed as executables
EXAMPLES_INSTALLED=	basic coursera_courses cryptocoinmarketcap factba.se hackernews_comments instagram openedx_courses reddit shopify_sitemap google_groups

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/modules.txt

post-install:
.for e in ${EXAMPLES_INSTALLED}
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${MV} ${e} ${PORTNAME}-${e}
.endfor

.include <bsd.port.mk>
