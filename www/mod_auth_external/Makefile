# New ports collection makefile for:	mod_auth_external
# Date created:				14 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_external
PORTVERSION=	2.1.19
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.unixpapa.com/software/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Enables the use of external mechanisms for user authentication

CONFLICTS=	apache-contrib-1.*

USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	AUTHENTICATORS CHANGES INSTALL README TODO
PORTEXAMPLES=	mysql radius sybase test

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
.for d in ${PORTEXAMPLES}
	${COPYTREE_SHARE} ${WRKSRC}/${d} ${EXAMPLESDIR}/${d}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
