# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	prips
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/prips/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prints IP subnet ranges by list or CIDR

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-2

MAKE_ENV=	CFLAGS_WARN="-Wall -W"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prips ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prips.1.gz ${STAGEDIR}${MANPREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
