# New ports collection makefile for:	pmw
# Date Created:				28 May 2004
# Whom:					Brian Candler <B.Candler@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	pmw
PORTVERSION=	4.05
CATEGORIES=	print audio
MASTER_SITES=	http://www.quercite.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High quality music typesetting program

ALL_TARGET=	build
GNU_CONFIGURE=	yes
MAN1=		pmw.1
PKGMESSAGE=	${WRKDIR}/pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog spec.pdf
.endif

post-patch:
	@${CAT} ${MASTERDIR}/pkg-message | ${SED} 's|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g' > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
