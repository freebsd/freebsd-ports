# New ports collection makefile for:	mod_dosevasive20
# Date created:				26 Jul 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mod_dosevasive20
PORTVERSION=	1.9
CATEGORIES=	www security
MASTER_SITES=	http://www.nuclearelephant.com/projects/dosevasive/
DISTNAME=	mod_dosevasive.${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	An Apache 2 module to try to protect HTTP DoS or DDoS attacks

WRKSRC=		${WRKDIR}/${PORTNAME}

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
WRKSRC=		${WRKDIR}/mod_dosevasive

PORTDOCS=	LICENSE README test.pl

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
