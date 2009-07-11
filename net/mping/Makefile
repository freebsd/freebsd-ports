# New ports collection makefile for:	mping
# Date Created:				19 Dec 2005
# Whom:					Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	mping
PORTVERSION=	2.01
CATEGORIES=	net ipv6
MASTER_SITES=	http://mping.uninett.no/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mping network statistics collector

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/mping
PORTDOCS=	ChangeLog README TODO

MAN8=		mping.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mping ${PREFIX}/sbin/mping
	${INSTALL_MAN} ${WRKSRC}/man/mping.8 ${PREFIX}/man/man8/mping.8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
