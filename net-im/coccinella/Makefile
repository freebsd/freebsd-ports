# New ports collection makefile for:	coccinella
# Date created:				21 Oct 2004
# Whom:					Marc Bruenink
#
# $FreeBSD$
#

PORTNAME=	coccinella
PORTVERSION=	0.95.1
CATEGORIES=	net-im tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Coccinella-${PORTVERSION}Src

MAINTAINER=	marc@bruenink.de
COMMENT=	Jabber client with whiteboard communication

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes

WISH=		${LOCALBASE}/bin/wish8.4
LIBTARGETDIR=	${PREFIX}/${PORTNAME}
PLIST_SUB+=	LIBTARGETDIR=${PORTNAME}

post-extract:
	@${RM} -r ${WRKSRC}/bin/

post-patch:
	@${REINPLACE_CMD} -e 's|\(exec.*\)wish|\1${WISH}|g' ${WRKSRC}/Coccinella.tcl

do-install:
	@${CP} -r ${WRKSRC} ${LIBTARGETDIR}
	@${RM} ${LIBTARGETDIR}/CHANGES ${LIBTARGETDIR}/README*
	@${INSTALL_SCRIPT} ${WRKSRC}/Coccinella.tcl ${LIBTARGETDIR}
	@${LN} -sf ${LIBTARGETDIR}/Coccinella.tcl ${PREFIX}/bin/coccinella

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README* ${DOCSDIR}
.endif

.include <bsd.port.mk>
