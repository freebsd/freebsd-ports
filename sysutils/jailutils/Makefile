# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	jailutils
PORTVERSION=	1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://thewalter.net/stef/freebsd/jails/jailutils/ \
		http://BSDforge.com/projects/source/sysutils/jailutils/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Several utilities for managing jails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
