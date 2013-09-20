# Created by: Michael Ranner <michael@ranner.eu>
# $FreeBSD$

PORTNAME=	duply
PORTVERSION=	1.5.9
CATEGORIES=	sysutils
MASTER_SITES=	SF/ftplicity/${PORTNAME}%20%28simple%20duplicity%29/1.5.x/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael@ranner.eu
COMMENT=	Shell front end for the duplicity backup tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		duplicity:${PORTSDIR}/sysutils/duplicity

NO_BUILD=	yes

PORTDOCS=	INSTALL.txt gpl-2.0.txt
PLIST_FILES=	bin/duply

NO_STAGE=	yes
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
