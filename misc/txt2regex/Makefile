# ex:ts=8
# New ports collection makefile for:	txt2regex
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	txt2regex
PORTVERSION=	0.4
CATEGORIES=	misc
MASTER_SITES=	http://txt2regex.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		gseq:${PORTSDIR}/misc/sh-utils

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,/bin/bash,${LOCALBASE}/bin/bash,g ; \
		s,\`seq,\`gseq,g" ${WRKSRC}/${DISTNAME}.sh
	@${PERL} -pi -e "s,/usr,${LOCALBASE},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.sh ${PREFIX}/bin/txt2regex

.include <bsd.port.mk>
