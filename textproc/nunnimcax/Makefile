# New ports collection makefile for:	NunniMCAX
# Date created:	   15 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	NunniMCAX
PORTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nunnimcax

MAINTAINER=	skv@FreeBSD.org
COMMENT=	C, non validating XML parser with SAX-like API

INSTALLS_SHLIB=	YES
SHLIB_MAJOR=	1
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	@${SED} -e "s=%%SHLIB_MAJOR%%=${SHLIB_MAJOR}=g" \
		${FILESDIR}/Makefile > ${WRKSRC}/Makefile

.include <bsd.port.mk>
