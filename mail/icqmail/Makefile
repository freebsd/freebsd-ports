# New ports collection makefile for:	icqmail
# Date created:		9 Jun 2000
# Whom:			Michael Vasilenko <acid@cn.ua>
#
# $FreeBSD$
#

PORTNAME=	icqmail
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	never@nevermind.kiev.ua

IGNORE=		"Does not work with newer version of protocol"

LIB_DEPENDS=	icq0.1:${PORTSDIR}/net/icqlib0 \
		guile.10:${PORTSDIR}/lang/guile

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		LIBS="-L${LOCALBASE}/lib -lguile -lqthreads"

MAN1=		icqmail.1

post-patch:
	@${PERL} -pi -e 's,Template ,Template ${PREFIX}/share/icqmail/,g' \
		${WRKSRC}/sample.cfg

.include <bsd.port.mk>
