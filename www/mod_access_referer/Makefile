# New ports collection makefile for:	mod_access_referer
# Date created:			18 Oct 2000
# Whom:				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	mod_access_referer
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	accessreferer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Apache module that provides access control based on Referer HTTP header

USE_APACHE=	yes
PORTDOCS=		HACKING LICENSE.txt ChangeLog README TODO mod_access_referer.html

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -i -A -n ${PORTNAME:S/mod_//} ${PORTNAME}.so)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
