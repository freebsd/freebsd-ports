# ex:ts=8
# New ports collection makefile for:	lsmlib
# Date created:			Jul 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lsmlib
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://lsmlib.sourceforge.net/releases/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lib that creates a libxml2 tree w/ info. token on a *NIX filesystem

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

XML2_CONFIG?=	${LOCALBASE}/bin/xml2-config
WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
MAKE_ENV=	XML2_CONFIG="${XML2_CONFIG}"
PLIST_FILES=	bin/lsm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsm ${PREFIX}/bin

.include <bsd.port.mk>
