PORTNAME=	prips
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/files/sys/prips/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prints IP subnet ranges by list or CIDR
WWW=		https://devel.ringlet.net/sysutils/prips/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-2

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prips ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/prips.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
