# New ports collection makefile for:	prips
# Date created:		29 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	prips
PORTVERSION=	0.9.6
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/prips/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Prints IP subnet ranges by list or CIDR

PORTDOCS=	README
PLIST_FILES=	bin/prips
MAN1=		prips.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prips ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/prips.1.gz ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
