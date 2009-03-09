# New ports collection makefile for:	spoofer
# Date created:		6 February 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spoofer
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	http://spoofer.csail.mit.edu/ CENKES

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	ANA Spoofer Project testing software

PLIST_FILES=	bin/spoofer
PORTDOCS=	README CHANGES

HAS_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
