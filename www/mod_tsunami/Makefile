# New ports collection makefile for:	mod_tsunami
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_tsunami
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-tsunami

MAINTAINER=	sysadmin@alexdupre.com

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs

DOCS=		AUTHORS Changelog INSTALL LICENSE README

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_tsunami.c

do-install:
	${APXS} -i -A -n tsunami ${WRKSRC}/mod_tsunami.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
