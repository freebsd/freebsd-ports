# New ports collection makefile for:	abook
# Date created:				June 6th 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	abook
PORTVERSION=	0.4.17
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	leeym@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

GNU_CONFIGURE=	yes

MAN1=		abook.1
MAN5=		abookrc.5
DOCS=		ANNOUNCE AUTHORS BUGS COPYING ChangeLog FAQ README THANKS TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
