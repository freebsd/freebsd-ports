# New ports collection makefile for:	duply
# Date created:		2010-09-25
# Whom:			Michael Ranner <michael@ranner.eu>
#
# $FreeBSD$
#

PORTNAME=	duply
PORTVERSION=	1.5.4.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/ftplicity/${PORTNAME}%20%28simple%20duplicity%29/1.5.x/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael@ranner.eu
COMMENT=	Shell front end for the duplicity backup tool

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		duplicity:${PORTSDIR}/sysutils/duplicity

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt
NO_BUILD=	yes

PORTDOCS=	INSTALL.txt gpl-2.0.txt
PLIST_FILES=	bin/duply

post-patch:
	@${REINPLACE_CMD} -e "s,/etc/duply,${ETCDIR},g" ${WRKSRC}/duply

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/duply ${PREFIX}/bin/duply
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.	for i in ${PORTDOCS}
	  @${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.	endfor
.endif

.include <bsd.port.mk>
