# ex:ts=8
# New ports collection makefile for:	wtail
# Date created:			Jan 11, 2003
# Whom:				mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	wtail
PORTVERSION=	0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	mich@freebsdcluster.org

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wtail ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
