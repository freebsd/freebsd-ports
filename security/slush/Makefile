# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	slush
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	crypt/SSL/slush

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A telnet-like application which uses a secure SSL channel

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/control.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/slush ${STAGEDIR}${PREFIX}/bin/slush
	${INSTALL_PROGRAM} ${WRKSRC}/slushd ${STAGEDIR}${PREFIX}/sbin/slushd

.include <bsd.port.mk>
