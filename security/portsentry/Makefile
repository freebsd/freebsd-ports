# New ports collection makefile for:	sentry
# Date created:		3 January 1998
# Whom:			chris@still.whet.org
#
# $FreeBSD$
#

PORTNAME=	portsentry
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/downloads/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Port scan detection and active defense

ALL_TARGET=	freebsd
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,__PREFIX__,${PREFIX},g' \
		${WRKSRC}/portsentry.conf ${WRKSRC}/portsentry_config.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/portsentry.conf ${PREFIX}/etc/portsentry.conf.default
	${INSTALL_DATA} ${WRKSRC}/portsentry.ignore ${PREFIX}/etc
	${INSTALL_PROGRAM} ${WRKSRC}/portsentry ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/portsentry
	${INSTALL_DATA} ${WRKSRC}/README.install ${WRKSRC}/README.methods ${WRKSRC}/README.stealth \
	  ${PREFIX}/share/doc/portsentry
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
