# New ports collection makefile for:	squidview
# Date created:		2007-04-21
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	squidview
PORTVERSION=	0.73
CATEGORIES=	www
MASTER_SITES=	http://www.rillion.net/squidview/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor squid statistics in realtime

GNU_CONFIGURE=	yes

MAN1=		squidview.1
DOCS=		HOWTO README
DATAFILES=	aliases users words

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squidview ${PREFIX}/bin/

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DATAFILES:S,^,${WRKSRC}/,} ${DATADIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	${INSTALL_MAN} ${WRKSRC}/squidview.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
