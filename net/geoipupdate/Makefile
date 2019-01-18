# Created by: adamw
# $FreeBSD$

PORTNAME=	geoipupdate
PORTVERSION=	4.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fetch the latest copies of the GeoIP2 databases

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	ca_root_nss>=3:security/ca_root_nss

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

MAKE_ENV+=	GOPATH=${WRKSRC} \
		CONFFILE=${PREFIX}/etc/GeoIP.conf \
		DATADIR=${PREFIX}/share/GeoIP

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
MANPAGES_PLIST_FILES=	man/man1/geoipupdate.1.gz \
			man/man5/GeoIP.conf.5.gz
MANPAGES_USES=		perl5
MANPAGES_USE=		perl5:build
MANPAGES_VARS=		MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/geoipupdate \
		'@sample etc/GeoIP.conf.sample' \
		'@dir share/GeoIP'
PORTDOCS=	GeoIP.conf.md geoipupdate.md

post-extract:
	${MV} ${WRKSRC}/vendor ${WRKSRC}/src

post-patch-MANPAGES-off:
	${REINPLACE_CMD} -e '/make-man-pages.pl/d' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/GeoIP
	${INSTALL_PROGRAM} ${WRKSRC}/build/geoipupdate ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/GeoIP.conf ${STAGEDIR}${PREFIX}/etc/GeoIP.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/build/geoipupdate.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/GeoIP.conf.5  ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
