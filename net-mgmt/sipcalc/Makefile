# Created by: Janos.Mohacsi@dante.org.uk
# $FreeBSD$

PORTNAME=	sipcalc
PORTVERSION=	1.1.6
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP subnet calculator with IPv6 support

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/sipcalc man/man1/sipcalc.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} sipcalc.txt \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
