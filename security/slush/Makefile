# Created by: shipley@dis.org

PORTNAME=	slush
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/crypt/SSL/slush

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Telnet-like application which uses a secure SSL channel

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.GPL

DEPRECATED=	Obsolete, listed as alpha quality, last release around 2000 and dead upstream
EXPIRATION_DATE=2022-03-31

GNU_CONFIGURE=	yes
USES=		ssl

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slush ${STAGEDIR}${PREFIX}/bin/slush
	${INSTALL_PROGRAM} ${WRKSRC}/slushd ${STAGEDIR}${PREFIX}/sbin/slushd

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/control.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
