# New ports collection makefile for:	paperkey
# Date created:		Mon Oct  6 12:56:53 EEST 2008
# Whom:			Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	paperkey
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.jabberwocky.com/software/paperkey/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Extract just the secret information out of OpenPGP secret keys

GNU_CONFIGURE=	yes
ALL_TARGET=	all check

PLIST_FILES=	bin/paperkey
MAN1=		paperkey.1
PORTDOCS=	NEWS README

.if !defined(NOPORTDOCS)
post-install:
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

.include <bsd.port.mk>
