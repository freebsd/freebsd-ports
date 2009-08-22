# New ports collection makefile for:	trn
# Date created:		21 October 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	trn
PORTVERSION=	4.0.b76
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}4/4.0%20test76
DISTNAME=	trn-4.0-test76

MAINTAINER=	johans@stack.nl
COMMENT=	Version 4.0 of the threaded readnews newsreader

NO_LATEST_LINK=	yes
IS_INTERACTIVE=	yes
MAN1=		trn.1 Pnews.1 Rnmail.1

.include <bsd.port.pre.mk>

pre-configure:
	@${ECHO_MSG} "===>  Running pre-configure target for ${DISTNAME}"
	@${SED} -e "s:__CC__:$(CC):" -e "s:__CFLAGS__:$(CFLAGS):" \
		-e "s:/PREFIX:$(PREFIX):"  ${SCRIPTDIR}/preconf > \
		${WRKDIR}/preconf.new
	@sh ${WRKDIR}/preconf.new ${PORTSDIR} ${.CURDIR} ${WRKSRC}

.include <bsd.port.post.mk>
