# New ports collection makefile for:	mod_auth_pam2
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_pam
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Allows users to use PAM modules for user authentication

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	mod_auth_pam2

USE_GMAKE=	YES
MAKE_ENV+=	APXS=${APXS}
WRKSRC=		${WRKDIR}/${PORTNAME}
APXS?=		${LOCALBASE}/sbin/apxs

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${EXAMPLESDIR}/pam-httpd.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
