# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nbtscan
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.inetcat.net/software/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetBIOS name network scanner

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}a
ALL_TARGET=	nbtscan

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
