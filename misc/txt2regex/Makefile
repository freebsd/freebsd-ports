# ex:ts=8
# New ports collection makefile for:	txt2regex
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	txt2regex
PORTVERSION=	0.7
CATEGORIES=	misc
MASTER_SITES=	http://txt2regex.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Regular Expression "wizard"

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_REINPLACE=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/txt2regex

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${LOCALBASE}/bin/bash,g ; \
		s,\`seq,\`gseq,g" ${WRKSRC}/${DISTNAME}.sh
	@${REINPLACE_CMD} -e "s,/usr,${LOCALBASE},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.sh ${PREFIX}/bin/txt2regex

.include <bsd.port.mk>
