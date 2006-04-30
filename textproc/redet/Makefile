# New ports collection makefile for:	redet
# Date created:		2005-07-18
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	redet
PORTVERSION=	8.10
CATEGORIES=	textproc tk84
MASTER_SITES=	http://bsd1.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vsevolod

MAINTAINER=	infofarmer@gmail.com
COMMENT=	Visual regexp constructors with many regexp types support

RUN_DEPENDS=	${LOCALBASE}/lib/iwidgets/iwidgets.tcl:${PORTSDIR}/x11-toolkits/iwidgets

NO_BUILD=	yes
USE_BZIP2=	yes
USE_TK=		84

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING CREDITS LICENSE README-General
MAN1=		redet.1
PLIST_FILES=	bin/redet

post-patch:
	@${REINPLACE_CMD} -e "s@exec wish@exec ${WISH}@" ${WRKSRC}/redet.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/redet.tcl ${PREFIX}/bin/redet
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
