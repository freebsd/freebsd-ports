# ex:ts=8
# Ports collection makefile for:	clpbar
# Date created:			Sep 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clpbar
PORTVERSION=	1.10.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	bar_${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Command Line Progress Bar

WRKSRC=		${WRKDIR}/bar-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--mandir=${MANPREFIX}/man
MAKE_ARGS+=	CFLAGS+="${CFLAGS}"

MAN1=		bar.1
PLIST_FILES=	bin/bar

.include <bsd.port.mk>
