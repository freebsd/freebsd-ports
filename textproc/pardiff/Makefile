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

PORTCOMMENT=	Parallelizing diff Filter, converts diff output to paralleled format

GNU_CONFIGURE=	yes

MAN1=	pardiff.1 diffp.1

DOCS=	AUTHORS ChangeLog README

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/pardiff
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/pardiff/
.endfor
.endif

.include <bsd.port.mk>
