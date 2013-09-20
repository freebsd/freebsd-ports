# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	mod_authnz_external
PORTVERSION=	3.1.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	apache2

MAINTAINER=	eg@fbsd.lt
COMMENT=	Allows users authentication based on external mechanisms on apache 2.2


USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	authnz_external
PROJECTHOST=	mod-auth-external

PORTDOCS=	AUTHENTICATORS INSTALL README	\
		CHANGES UPGRADE INSTALL.HARDCODE

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
