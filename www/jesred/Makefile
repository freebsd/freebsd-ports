PORTNAME=	jesred
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.linofee.org/~jel/webtools/src/ \
		http://www.acad.bg/ftp/pub/src/misc/
DISTNAME=	jesred-1.2pl1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Redirector for Squid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jesred ${STAGEDIR}${PREFIX}/libexec
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/jesred
	${INSTALL_DATA} ${WRKSRC}/etc/jesred.conf \
		${STAGEDIR}${PREFIX}/etc/jesred/jesred.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/redirect.acl \
		${STAGEDIR}${PREFIX}/etc/jesred/redirect.acl.sample
	${INSTALL_DATA} ${WRKSRC}/etc/redirect.rules \
		${STAGEDIR}${PREFIX}/etc/jesred/redirect.rules.sample

.include <bsd.port.mk>
