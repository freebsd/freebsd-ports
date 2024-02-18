PORTNAME=	makiki
PORTVERSION=	0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www scheme
PKGNAMEPREFIX=	gauche-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple multithreaded HTTP server written in Gauche
WWW=		https://github.com/shirok/Gauche-makiki

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gosh:lang/gauche
RUN_DEPENDS=	gosh:lang/gauche

HAS_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	shirok
GH_PROJECT=	Gauche-makiki

GUILE_SITELIBDIR_REL=	${:!gauche-config --sitelibdir!:S,^${PREFIX}/,,}

EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}

PLIST_FILES=	${GUILE_SITELIBDIR_REL}/.packages/Gauche-makiki.gpd \
		${GUILE_SITELIBDIR_REL}/makiki/cgi.scm \
		${GUILE_SITELIBDIR_REL}/makiki/connect.scm \
		${GUILE_SITELIBDIR_REL}/makiki/dev.scm \
		${GUILE_SITELIBDIR_REL}/makiki/session.scm \
		${GUILE_SITELIBDIR_REL}/makiki/subserver.scm \
		${GUILE_SITELIBDIR_REL}/makiki.scm
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
