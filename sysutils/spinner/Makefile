PORTNAME=	spinner
PORTVERSION=	1.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/spinner/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep ssh and telnet connections from dropping due to inactivity

GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spinner ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
