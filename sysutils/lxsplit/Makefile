# New ports collection makefile for:   lxsplit
# Date created:        9 April 2003
# Whom:                kiesel@schlund.de
#
# $FreeBSD$
#

PORTNAME=	lxsplit
PORTVERSION=	0.2.4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Simple program to split or join files

PLIST_FILES=	bin/lxsplit
PORTDOCS=	COPYING ChangeLog README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lxsplit ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
