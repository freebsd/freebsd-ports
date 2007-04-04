# New ports collection makefile for:	ts
# Date created:		3 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ts
PORTVERSION=	0.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://vicerveza.homeunix.net/~viric/soft/ts/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Serial task spooler

WRKSRC=		${WRKDIR}/ts
ALL_TARGET=	ts
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	OBJECTIVES PROTOCOL README TRICKS Changelog
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|$$^|$${.ALLSRC}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
