# New ports collection makefile for:	sarah
# Date created:		10 Jan 2000
# Whom:			Matthew Pounsett <mattp@conundrum.com>
#
# $FreeBSD$
#

PORTNAME=	sarah
PORTVERSION=	0.8b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.conundrum.com/pub/sarah/

MAINTAINER=	mattp@conundrum.com

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		sarah.1

do-configure:
	@${PERL} -pi.orig -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/sarah

do-install:
	cd ${WRKSRC} && \
		${INSTALL_SCRIPT} sarah ${PREFIX}/bin && \
		${INSTALL_DATA} sarah.conf.sample ${PREFIX}/etc && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sarah
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/sarah
	${INSTALL_MAN} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/sarah
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/sarah
.endif

.include <bsd.port.mk>
