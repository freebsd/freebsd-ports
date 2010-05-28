# New ports collection makefile for:	dash
# Date created:			Nov 10, 2009
# Whom:				Eitan Adler
#
# $FreeBSD$
#

PORTNAME=	dash
PORTVERSION=	0.5.6
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	ports@eitanadler.com
COMMENT=	A POSIX-compliant implementation of /bin/sh

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-DUNUSABLE_RT_SIGNALS

PLIST_FILES=	bin/dash
MAN1=		dash.1

post-patch:
	@${REINPLACE_CMD} -e '/COMMON_CFLAGS =/ s|$$| ${CFLAGS}|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
