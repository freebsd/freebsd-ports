# Created by: obrien@NUXI.com
# $FreeBSD$

PORTNAME=	rclock
PORTVERSION=	2.7.10
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	SF/rxvt/rxvt-dev/${PORTVERSION}
DISTNAME=	rxvt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analog clock for X w/appointment reminder and mail notification

LICENSE=	GPLv2+

USES=		xorg
USE_XORG=	x11 xau xdmcp ice xpm xv
GNU_CONFIGURE=	yes
ALL_TARGET=	clock

PLIST_FILES=	bin/rclock man/man1/rclock.1.gz

CPPFLAGS+=	-DMAIL_SPOOL='\"/var/mail/\"'

post-patch:
	@${REINPLACE_CMD} \
		's|^subdirs =.*$$|subdirs = rclock|g' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
