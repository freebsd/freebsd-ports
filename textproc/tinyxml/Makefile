# New ports collection makefile for:	tinyxml
# Date created:	   28 July 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	tinyxml
PORTVERSION=	2.3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Small C++ XML parser

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	PREFIX=${PREFIX}

INSTALLS_SHLIB=	YES
SHLIB_MAJOR=	1
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.if defined(NOPROFILE)
PLIST_SUB+=      PROFILE="@comment "
.else
PLIST_SUB+=      PROFILE=""
.endif

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	@${SED} -e "s=%%SHLIB_MAJOR%%=${SHLIB_MAJOR}=g" \
		${FILESDIR}/Makefile > ${WRKSRC}/Makefile

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
