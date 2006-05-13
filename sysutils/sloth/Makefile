# ex:ts=8
# Ports collection makefile for:	sloth
# Date created:			May 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sloth
PORTVERSION=	1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://communityprojects.org/apps/sloth/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slow down a process

GNU_CONFIGURE=	yes

MAN1=		sloth.1
PLIST_FILES=	bin/sloth

post-patch:
	@${REINPLACE_CMD} -e "s,wait.h,sys/wait.h,g" ${WRKSRC}/configure

.include <bsd.port.mk>
