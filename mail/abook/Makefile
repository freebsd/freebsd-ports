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
COMMENT=	An addressbook program with mutt mail client support

GNU_CONFIGURE=	yes

MAN1=		abook.1
MAN5=		abookrc.5
DOCS=		ANNOUNCE AUTHORS BUGS COPYING ChangeLog FAQ INSTALL NEWS README THANKS TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
