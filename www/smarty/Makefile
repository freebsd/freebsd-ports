# New ports collection makefile for:	smarty
# Date created:		10 March 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	smarty
PORTVERSION=	2.6.9
CATEGORIES=	www
MASTER_SITES=	http://smarty.php.net/distributions/ \
		http://smarty.php.net/distributions/manual/en/:manual
DISTFILES=	Smarty-${PORTVERSION}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	Smarty-2.6.9-docs${EXTRACT_SUFX}:manual
.endif

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	The PHP compiling template engine

WRKSRC=	${WRKDIR}/Smarty-${PORTVERSION}

NO_BUILD=	yes
USE_PHP=	yes
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
MSG_SRC=	${FILESDIR}/pkg-message

MSG_SUB=	DATADIR=${DATADIR} LOCALBASE=${LOCALBASE}

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
	@${SED} ${MSG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${MSG_SRC} > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
