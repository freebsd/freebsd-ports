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
COMMENT=	Provides access control based on Referer HTTP header for Apache

WANT_APACHE=	13
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
PORTDOCS=		HACKING LICENSE.txt ChangeLog README TODO mod_access_referer.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
