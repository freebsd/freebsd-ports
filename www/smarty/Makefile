# New ports collection makefile for:	smarty
# Date created:		10 March 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	smarty
PORTVERSION=	2.3.0
CATEGORIES=	www
MASTER_SITES=	http://smarty.php.net/distributions/ \
		http://smarty.php.net/distributions/manual/en/:manual
DISTFILES=	Smarty-${PORTVERSION}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	Smarty-${PORTVERSION}-docs${EXTRACT_SUFX}:manual
.endif

MAINTAINER=	corecode@corecode.ath.cx

RUN_DEPENDS=	php-config:${PORTSDIR}/www/mod_php4

WRKSRC=	${WRKDIR}/Smarty-${PORTVERSION}

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
MSG_SRC=${FILESDIR}/pkg-message

MSG_SUB=	DATADIR=${DATADIR} LOCALBASE=${LOCALBASE}

CPIO?=	/usr/bin/cpio

do-install:
	@${MKDIR} ${DATADIR}
.for f in Config_File.class.php Smarty.class.php Smarty_Compiler.class.php debug.tpl
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/plugins
	@${INSTALL_DATA} ${WRKSRC}/plugins/* ${DATADIR}/plugins
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in BUGS FAQ INSTALL NEWS QUICKSTART README RESOURCES
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/manual
	@cd ${WRKDIR}/manual && ${FIND} . | ${CPIO} --quiet -dumpR ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/manual
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/index.php ${EXAMPLESDIR}
.for f in configs templates templates_c cache
	@${MKDIR} ${EXAMPLESDIR}/$f
	@-${INSTALL_DATA} ${WRKSRC}/$f/* ${EXAMPLESDIR}/$f 2>/dev/null || ${TRUE}
.endfor
.endif

post-install:
	@${SED} ${MSG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${MSG_SRC} > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
