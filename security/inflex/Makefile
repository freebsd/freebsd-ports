# New ports collection Makefile for:	inflex
# Date created:		18 August 2000
# Whom:			Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	inflex
PORTVERSION=	0.1.5.c
CATEGORIES=	security
MASTER_SITES=	http://www.inflex.co.za/
DISTNAME=	inflex-0.1.5c

MAINTAINER=	jus@security.za.net

RUN_DEPENDS=	${LOCALBASE}/bin/metamail:${PORTSDIR}/mail/metamail \
		${LOCALBASE}/bin/formail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/inflex ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/inflex.cf ${PREFIX}/etc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/inflex
.for FILE in AUTHORS CHANGELOG COPYRIGHT EXIM_USERS README.1ST THANKS TODO \
	     UNINSTALL ModifyingInflex
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/doc/inflex
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
