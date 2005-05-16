# ex:ts=8
# Ports collection makefile for:	clpbar
# Date created:			Sep 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clpbar
PORTVERSION=	1.10.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	bar-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command Line Progress Bar

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		bar.1
PLIST_FILES=	bin/bar

post-patch:
	@${REINPLACE_CMD} -e 's|= -O2|= @CFLAGS@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
