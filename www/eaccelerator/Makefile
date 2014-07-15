# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	eaccelerator
PORTVERSION=	0.9.7
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A free open-source PHP accelerator & optimizer

LICENSE=	GPLv2
OPTIONS_DEFINE=	DOCCOMM DOCS EXAMPLES
DOCCOMM_DESC=	Retain doc-comments in internal php structures

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	42067ac

DOCCOMM_DESC=	Retain doc-comments in internal php structures
DOCCOMM_CONFIGURE_WITH=	eaccelerator-doc-comment-inclusion

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes

CONFIGURE_ARGS=	--enable-eaccelerator=shared \
		--with-eaccelerator-userid=80

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/control.php ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dasm.php ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
