# ex:ts=8
# New ports collection makefile for:	ija
# Date created:			Feb 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ija
PORTVERSION=	0.4.15
CATEGORIES=	news
MASTER_SITES=	http://wildspark.com/asher/ija/
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive command line frontend of Deja

RUN_DEPENDS=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/ija

do-extract:
	@${MKDIR} ${WRKDIR}
	@${GUNZIP_CMD} -c ${DISTDIR}/${DISTFILES} > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
