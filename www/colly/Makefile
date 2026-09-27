PORTNAME=	colly
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Elegant scraper and crawler framework for Golang
WWW=		https://go-colly.org/ \
		https://github.com/gocolly/colly

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
#USE_GITHUB=	yes
#GH_ACCOUNT=	gocolly

GO_MODULE=	github.com/gocolly/colly/v2
GO_TARGET=	./cmd/${PORTNAME} \
		${EXAMPLES_INSTALLED:S/^/.\/_examples\//}

PLIST_FILES=	bin/${PORTNAME} \
		${EXAMPLES_INSTALLED:S/^/bin\/${PORTNAME}-/}

# many examples of this sraping framework are interesting in themselves, and therefore are installed as executables
EXAMPLES_INSTALLED=	basic coursera_courses cryptocoinmarketcap factba.se hackernews_comments instagram openedx_courses reddit shopify_sitemap google_groups

post-install:
.for e in ${EXAMPLES_INSTALLED}
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${MV} ${e} ${PORTNAME}-${e}
.endfor

.include <bsd.port.mk>
