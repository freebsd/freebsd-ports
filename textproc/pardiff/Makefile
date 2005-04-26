# New ports collection makefile for:	pardiff
# Date created:		08 July 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	pardiff
PORTVERSION=	0.9.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pardiff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallelizing diff Filter, converts diff output to paralleled format

GNU_CONFIGURE=	yes

MAN1=	pardiff.1 diffp.1

PLIST_FILES=	bin/pardiff bin/diffp
.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog README
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/pardiff
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/pardiff/
.endfor
.endif

.include <bsd.port.mk>
