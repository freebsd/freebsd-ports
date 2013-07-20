# $FreeBSD$

PORTNAME=	mod_macro
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	http://www.cri.ensmp.fr/~coelho/mod_macro/

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	Apache 2.4.x module for use macros in config files

LICENSE=	mod_macro
LICENSE_NAME=	mod_macro license (apache with postcard request)
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_SAFE=	yes

IGNORE=		apache24-2.4.6 and newer delivers this module by default
EXPIRATION_DATE=2013-08-03

USE_APACHE=	24
LATEST_LINK=	mod_macro24
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
PORTDOCS=	${PORTNAME}.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
