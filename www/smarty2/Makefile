# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	smarty
PORTVERSION=	2.6.28
CATEGORIES=	www
MASTER_SITES=	http://www.smarty.net/files/ \
		http://www.smarty.net/files/docs/:manual
DISTFILES=	Smarty-${PORTVERSION}${EXTRACT_SUFX} \
		manual-en-${DOCSVERSION}${EXTRACT_SUFX}:manual

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PHP compiling template engine

USES=		zip

DOCSVERSION=	2.6

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/Smarty-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in Config_File.class.php Smarty.class.php Smarty_Compiler.class.php debug.tpl
	${INSTALL_DATA} ${WRKSRC}/libs/$f ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/internals
	${INSTALL_DATA} ${WRKSRC}/libs/internals/* ${STAGEDIR}${DATADIR}/internals
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/libs/plugins/* ${STAGEDIR}${DATADIR}/plugins
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in BUGS FAQ INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	cd ${WRKDIR}/manual-en && ${FIND} . | ${CPIO} --quiet -dump ${STAGEDIR}${DOCSDIR}/manual

.include <bsd.port.mk>
