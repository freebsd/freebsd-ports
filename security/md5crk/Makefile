# New ports collection makefile for:	md5crk
# Date created:				2004-03-26
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	md5crk
PORTVERSION=	1.0.4
CATEGORIES=	security parallel
MASTER_SITES=	http://www.md5crk.com/dl/
DISTNAME=	md5crk_${PORTVERSION}_freebsdX86

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Distributed project to generate MD5 collisions (i386 binary)

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
.endif

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/md5crk
RESTRICTED=	"no commercial use"
WRKSRC=		${WRKDIR}/md5crk_1.0.3_freebsdX86

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/md5crk ${PREFIX}/bin

.include <bsd.port.post.mk>
