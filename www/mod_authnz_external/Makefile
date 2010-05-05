# New ports collection makefile for:   	mod_authnz_external
# Date created:        			March 26, 2007
# Whom:                			José García Juanino <jjuanino@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mod_authnz_external
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	apache22

MAINTAINER=	eg@fbsd.lt
COMMENT=	Allows users authentication based on external mechanisms on apache 2.2

USE_APACHE=	22
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
SHORTMODNAME=	authnz_external
PROJECTHOST=	mod-auth-external

PORTDOCS=	AUTHENTICATORS INSTALL README	\
		CHANGES UPGRADE INSTALL.HARDCODE

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
