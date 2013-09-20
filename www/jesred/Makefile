# Created by: dsh@vlink.ru
# $FreeBSD$

PORTNAME=	jesred
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.linofee.org/~jel/webtools/src/ \
		http://www.acad.bg/ftp/pub/src/misc/
DISTNAME=	jesred-1.2pl1

MAINTAINER=	dsh@vlink.ru
COMMENT=	A redirector for Squid

NO_STAGE=	yes
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
