# New ports collection makefile for:	jesred
# Version required:	1.2.pl1
# Date created:		Mon Nov  8 17:42:20 MSK 1999
# Whom:			dsh@vlink.ru
#
# $FreeBSD$
#

DISTNAME=	jesred-1.2pl1
PKGNAME=	jesred-1.2.1
CATEGORIES=	www
MASTER_SITES=	http://ivs.cs.uni-magdeburg.de/~elkner/webtools/src/

MAINTAINER=	dsh@vlink.ru

RUN_DEPENDS=	squid:${PORTSDIR}/www/squid22

do-install:
	${INSTALL_PROGRAM} ${COPY} ${WRKSRC}/jesred ${PREFIX}/libexec
	${SED} "s!%%PREFIX%%!${PREFIX}!" < ${WRKSRC}/etc/jesred.conf \
		> ${WRKSRC}/etc/jesred.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/jesred.conf.sample ${PREFIX}/etc/squid
	${INSTALL_DATA} ${COPY} ${WRKSRC}/etc/redirect.acl \
		${PREFIX}/etc/squid/redirect.acl.sample
	${INSTALL_DATA} ${COPY} ${WRKSRC}/etc/redirect.rules \
		${PREFIX}/etc/squid/redirect.rules.sample
	@[ -f ${PREFIX}/etc/squid/jesred.conf ] || \
		${CP} ${PREFIX}/etc/squid/jesred.conf.sample \
		${PREFIX}/etc/squid/jesred.conf

.include <bsd.port.mk>
