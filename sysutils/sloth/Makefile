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
MASTER_SITES=	ftp://ftp.namodn.com/pub/projects/ \
		http://communityprojects.org/apps/sloth/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Slow down a process

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN1=	sloth.1

post-patch:
	@${REINPLACE_CMD} -e "s,wait.h,sys/wait.h,g" ${WRKSRC}/configure

.include <bsd.port.mk>
