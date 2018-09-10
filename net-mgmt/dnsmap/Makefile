# Created by: Rihaz Jerrin <rihaz.jerrin@gmail.com>
# $FreeBSD$

PORTNAME=	dnsmap
PORTVERSION=	0.30
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	DNS domain name brute forcing tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

USE_GITHUB=	yes
GH_ACCOUNT=	lifanov

PORTDOCS=	Changelog.txt README.txt CREDITS.txt use_cases.txt

PLIST_FILES=	bin/dnsmap bin/dnsmap-bulk ${DATADIR}/wordlist_TLAs.txt

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/dnsmap.c -o ${WRKSRC}/dnsmap

do-install:
	 ${INSTALL_PROGRAM}  ${WRKSRC}/${PORTNAME}            ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	 ${INSTALL_SCRIPT}   ${WRKSRC}/${PORTNAME}-bulk.sh    ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-bulk
	 ${MKDIR}	     ${STAGEDIR}${DATADIR}
	 ${INSTALL_DATA}     ${WRKSRC}/wordlist_TLAs.txt      ${STAGEDIR}${DATADIR}
	 ${MKDIR}	     ${STAGEDIR}${DOCSDIR}
	 ${INSTALL_DATA}     ${PORTDOCS:S|^|${WRKSRC}/|}      ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
