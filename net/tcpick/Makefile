# New ports collection makefile for:   tcpick
# Date created:        09 January 2005
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tcpick
PORTVERSION=	0.2.0.r6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A text-based TCP stream sniffer

GNU_CONFIGURE=	yes

MANLANG=	"" it
MAN8=		tcpick.8

PLIST_FILES=	bin/tcpick

post-install:
	${MKDIR} ${PREFIX}/man/it/man8
	${MV} ${PREFIX}/man/man8/tcpick_italian.8 ${PREFIX}/man/it/man8/tcpick.8

.include <bsd.port.mk>
