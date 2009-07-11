# New ports collection makefile for:	redet
# Date created:		2005-07-18
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	redet
PORTVERSION=	8.26
CATEGORIES=	textproc tk
MASTER_SITES=	http://www.billposer.org/Software/Downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual regexp development and execution

RUN_DEPENDS=	${LOCALBASE}/lib/iwidgets/iwidgets.tcl:${PORTSDIR}/x11-toolkits/iwidgets

NO_BUILD=	yes
USE_BZIP2=	yes
USE_TK_RUN=	84

PORTDOCS=	AUTHORS COPYING CREDITS LICENSE NEWS README-General ChangeLog
MAN1=		redet.1
PLIST_FILES=	bin/redet

post-patch:
	@${REINPLACE_CMD} -e "s@exec wish@exec ${WISH}@" ${WRKSRC}/redet.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/redet.tcl ${PREFIX}/bin/redet
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
