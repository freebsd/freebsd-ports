# New ports collection makefile for:	deleted
# Date created:				2000 May 25
# Whom:					@BABOLO <.@babolo.ru>
#
# $FreeBSD$
#

PORTNAME=	deleted
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/sysutl/ \
		http://www.links.ru/soft/

MAINTAINER=	.@babolo.ru

MAN1=		deleted.1
MANCOMPRESSED=	yes
BINMODE=	4555

post-install:
	@${CHMOD} 4555 ${PREFIX}/bin/deleted

.include <bsd.port.mk>
