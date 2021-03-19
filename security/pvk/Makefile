# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pvk
PORTVERSION=	20070406
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.drh-consultancy.demon.co.uk/ \
		http://vault.101011010.xyz/distfiles/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	pvksrc
EXTRACT_SUFX=	.tgz.bin

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Tool to convert a RSA key in PEM format into a PVK file and vice versa

USES=		ssl
MAKE_ARGS=	SSLINC=${OPENSSLINC} SSLLIB=${OPENSSLLIB}

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/pvk
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pvk ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
