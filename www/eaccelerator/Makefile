# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	eaccelerator
PORTVERSION=	0.9.7
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A free open-source PHP accelerator & optimizer

LICENSE=	GPLv2
OPTIONS_DEFINE=	DOCCOMM
DOCCOMM_DESC=	Retain doc-comments in internal php structures

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	42067ac

OPTIONS_DEFINE=	DOCCOMM

DOCCOMM_DESC=	Retain doc-comments in internal php structures

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes

CONFIGURE_ARGS=	--enable-eaccelerator=shared \
		--with-eaccelerator-userid=80

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCCOMM}
CONFIGURE_ARGS+=--with-eaccelerator-doc-comment-inclusion
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/control.php ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dasm.php ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
