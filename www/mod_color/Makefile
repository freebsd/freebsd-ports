# New ports collection makefile for:	mod_auth_pam
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_color
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://www.dimensional.com/~bgiles/mod_color/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.l

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs
NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	lex -t -Psyncc ${WRKSRC}/mod_color.l > ${WRKSRC}/mod_color.c
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
