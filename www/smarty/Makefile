# New ports collection makefile for:	smarty
# Date created:		10 March 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	smarty
PORTVERSION=	2.6.26
CATEGORIES=	www
MASTER_SITES=	http://www.smarty.net/distributions/ \
		http://www.smarty.net/distributions/manual/en/:manual
DISTFILES=	Smarty-${PORTVERSION}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	Smarty-${DOCSVERSION}-docs${EXTRACT_SUFX}:manual
.endif

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	The PHP compiling template engine

DOCSVERSION=	2.6.14

WRKSRC=		${WRKDIR}/Smarty-${PORTVERSION}

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
.for f in Config_File.class.php Smarty.class.php Smarty_Compiler.class.php debug.tpl
	@${INSTALL_DATA} ${WRKSRC}/libs/$f ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/internals
	@${INSTALL_DATA} ${WRKSRC}/libs/internals/* ${DATADIR}/internals
	@${MKDIR} ${DATADIR}/plugins
	@${INSTALL_DATA} ${WRKSRC}/libs/plugins/* ${DATADIR}/plugins
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in BUGS FAQ INSTALL NEWS README
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/manual
	@cd ${WRKDIR}/manual && ${FIND} . | ${CPIO} --quiet -dumpR ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/manual
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
