# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	relay
PORTVERSION=	1.10
CATEGORIES=	net security
MASTER_SITES=	http://www.iagora.com/~espel/  \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	relay

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP proxy server with telnet, ftp, finger client wrappers

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

IS_INTERACTIVE=	'must set server hostname in relay.h'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/relay ${PREFIX}/libexec
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} rtelnet rftp rfinger ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/relay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/relay
.endif

.include <bsd.port.mk>
