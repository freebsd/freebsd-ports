PORTNAME=	jailutils
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://thewalter.net/stef/freebsd/jails/jailutils/ \
		https://BSDforge.com/projects/source/sysutils/jailutils/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Several utilities for managing jails
WWW=		http://thewalter.net/stef/freebsd/jails/jailutils/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	AUTHORS ChangeLog

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
