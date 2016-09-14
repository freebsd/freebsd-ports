# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	mod_authnz_external
PORTVERSION=	3.1.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	22
DIST_SUBDIR=	apache2

MAINTAINER=	eg@fbsd.lt
COMMENT=	Allows users authentication based on external mechanisms on apache 2.2

LICENSE=	APACHE20

BROKEN=		Unfetchable (google code has gone away)

USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	authnz_external
PROJECTHOST=	mod-auth-external

PORTDOCS=	AUTHENTICATORS INSTALL README	\
		CHANGES UPGRADE INSTALL.HARDCODE

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
