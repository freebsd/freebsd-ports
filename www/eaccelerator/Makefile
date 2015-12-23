# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	eaccelerator
PORTVERSION=	0.9.7
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Free open-source PHP accelerator & optimizer

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCCOMM DOCS EXAMPLES
DOCCOMM_DESC=	Retain doc-comments in internal php structures

USE_GITHUB=	yes
GH_TAGNAME=	42067ac

DOCCOMM_DESC=	Retain doc-comments in internal php structures
DOCCOMM_CONFIGURE_WITH=	eaccelerator-doc-comment-inclusion

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
IGNORE_WITH_PHP=	55 56

CONFIGURE_ARGS=	--enable-eaccelerator=shared \
		--with-eaccelerator-userid=80

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/control.php ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dasm.php ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
