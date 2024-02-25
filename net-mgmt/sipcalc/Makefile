PORTNAME=	sipcalc
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP subnet calculator with IPv6 support
WWW=		https://www.routemeister.net/projects/sipcalc/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	*
PLIST_FILES=	bin/sipcalc share/man/man1/sipcalc.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} sipcalc.txt \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
