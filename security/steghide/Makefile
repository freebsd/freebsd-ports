# New ports collection makefile for:	steghide
# Date created:				26 February 2001
# Whom:					RaRa Rasputin <rasputin@submonkey.net>
#
# $FreeBSD$
#

PORTNAME=	steghide
PORTVERSION=	0.4.4
CATEGORIES=	security
MASTER_SITES=	http://steghide.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mcrypt.7:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

MAN1=		steghide.1

.include <bsd.port.mk>
