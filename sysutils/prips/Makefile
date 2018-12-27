# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	prips
PORTVERSION=	1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/files/sys/prips/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Prints IP subnet ranges by list or CIDR

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-2

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prips ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prips.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
