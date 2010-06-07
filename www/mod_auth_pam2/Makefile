# New ports collection makefile for:	mod_auth_pam2
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_pam
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to use PAM modules for user authentication

MAKE_JOBS_SAFE=	yes

LATEST_LINK=	mod_auth_pam2

USE_APACHE=	20+
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*.html
PORTEXAMPLES=	pam-httpd.sample

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${EXAMPLESDIR}/pam-httpd.sample
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
