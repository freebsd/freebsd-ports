# New ports collection makefile for:	diskscrub
# Date created:		28 November 2006
# Whom:			Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	diskscrub
PORTVERSION=	1.9
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	scrub-${PORTVERSION}

MAINTAINER=	erik@smluc.org
COMMENT=	Writes patterns on files to make retrieving the data more difficult

MAN1=	scrub.1

PLIST_FILES=	bin/scrub

USE_GMAKE=	yes
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS=/CFLAGS?=/'	\
	                  -e 's/^CC=/CC?=/'		\
	                  ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scrub ${PREFIX}/bin/scrub
	${INSTALL_MAN} ${WRKSRC}/scrub.1 ${MAN1PREFIX}/man/man1/scrub.1

.include <bsd.port.mk>
