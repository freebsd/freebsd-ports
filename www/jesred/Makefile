# New ports collection makefile for:	jesred
# Date created:		Mon Nov  8 17:42:20 MSK 1999
# Whom:			dsh@vlink.ru
#
# $FreeBSD$
#

PORTNAME=	jesred
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	http://ivs.cs.uni-magdeburg.de/~elkner/webtools/src/
DISTNAME=	jesred-1.2pl1

MAINTAINER=	dsh@vlink.ru

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jesred ${PREFIX}/libexec
	${MKDIR} ${PREFIX}/etc/jesred
	${INSTALL_DATA} ${WRKSRC}/etc/jesred.conf \
		${PREFIX}/etc/jesred/jesred.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/redirect.acl \
		${PREFIX}/etc/jesred/redirect.acl.sample
	${INSTALL_DATA} ${WRKSRC}/etc/redirect.rules \
		${PREFIX}/etc/jesred/redirect.rules.sample

.include <bsd.port.mk>
