# New ports collection makefile for:	x86info
# Date created:			26 Aug 2001
# Whom:				Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	x86info
PORTVERSION=	1.17
CATEGORIES=	sysutils
MASTER_SITES=	http://www.codemonkey.org.uk/projects/x86info/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org
COMMENT=	Utility to display information about the systems x86 processor(s)

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/x86info
MAKE_ARGS=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x86info ${PREFIX}/bin

.include <bsd.port.mk>
