# New ports collection makefile for:	webredirect
# Date created:		24 October 2000
# Whom:			kaj@Raditex.se
#
# $FreeBSD$
#

PORTNAME=	webredirect
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.stacken.kth.se/pub/projects/webredirect/

MAINTAINER=	rasmus@kaj.se
COMMENT=	Small web server serving "301 Moved Permanently" only

ALL_TARGET=	depend all

MAN1=		webredirect.1
PLIST_FILES=	bin/webredirect

.include <bsd.port.pre.mk>

pre-build:
	@${TOUCH} ${WRKSRC}/incu/depend.mk
	@${TOUCH} ${WRKSRC}/depend.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webredirect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webredirect.1 ${PREFIX}/man/man1

post-install:
	@${SETENV} ${MAKE_ENV} ${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
