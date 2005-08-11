# New ports collection makefile for:	redet
# Date created:		2005-07-18
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	redet
PORTVERSION=	6.14
CATEGORIES=	textproc tk84
MASTER_SITES=	http://www.billposer.org/Software/Downloads/
DISTNAME=	${PORTNAME}tiny-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Visual regexp constructors with many regexp types support

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING CREDITS LICENSE README-General
MAN1=		redet.1
PLIST_FILES=	bin/redet

post-patch:
	@${REINPLACE_CMD} -e 's/wish/wish8.4/' ${WRKSRC}/redet.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/redet.tcl ${PREFIX}/bin/redet
	${INSTALL_DATA} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
