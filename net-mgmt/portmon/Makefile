# New ports collection makefile for:	portmon
# Date created:				18.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	portmon
PORTVERSION=	1.8
CATEGORIES=	net
MASTER_SITES=	http://www.aboleo.net/software/portmon/downloads/

MAINTAINER=	ponomarew@oberon.net
COMMENT=	Daemon that monitor network services

GNU_CONFIGURE=	yes

MAN8=		portmon.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/extras/portmon.8 \
		${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/extras/portmon.hosts.sample \
		${PREFIX}/etc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
