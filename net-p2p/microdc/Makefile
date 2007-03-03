# New ports collection makefile for:   microdc
# Date created:                2006-08-11
# Whom:                        Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	microdc
PORTVERSION=	0.11.0
PORTREVISION=	1	
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pankov_p@mail.ru
COMMENT=	A command-line based Direct Connect client

DEPRECATED=	microdc is no longer in development. Consider using net-p2p/microdc2 instead
EXPIRATION_DATE=2007-05-03

USE_GCC=	3.2+
GNU_CONFIGURE=	yes
USE_ICONV=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	 NLS="@comment "
.endif

MAN1=	${PORTNAME}.1
MANLANG=	"" pl

post-install:
	@${MKDIR} ${MAN1PREFIX}/man/pl
	@${MKDIR} ${MAN1PREFIX}/man/pl/man1
	@${MV} ${MAN1PREFIX}/man/man1/${PORTNAME}.pl.1 ${MAN1PREFIX}/man/pl/man1/${PORTNAME}.1

.include <bsd.port.mk>
