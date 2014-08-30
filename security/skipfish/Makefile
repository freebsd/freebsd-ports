# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	skipfish
PORTVERSION=	2.10b
PORTREVISION=	2
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Fully automated, active web application security reconnaissance tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn \
		libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake tar:tgz
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README COPYING ChangeLog

post-patch:
	@${REINPLACE_CMD} -e 's:"skipfish.wl":"${DATADIR}/dictionaries/complete.wl":' \
		-e 's:"assets":"${DATADIR}/assets":' ${WRKSRC}/src/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skipfish ${STAGEDIR}${PREFIX}/bin/skipfish
	${INSTALL_SCRIPT} ${WRKSRC}/tools/sfscandiff ${STAGEDIR}${PREFIX}/bin/sfscandiff
	${INSTALL_MAN} ${WRKSRC}/doc/skipfish.1 ${STAGEDIR}${PREFIX}/man/man1
	(cd ${WRKSRC}/assets/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/assets/)
	(cd ${WRKSRC}/dictionaries/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/dictionaries/)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for doc in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.	endfor

.include <bsd.port.mk>
