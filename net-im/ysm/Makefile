# New ports collection makefile for:	ysm
# Date created:				May 28, 2002
# Whom:					vampiro
#
# $FreeBSD$
#

PORTNAME=	ysm
PORTVERSION=	7.2.8.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://vampiro.rootshell.ru/pub/FreeBSD/distfiles/ \
		http://vampiro.rootshell.ru/ \
		ftp://ftp.treasury.ru/pub/unix/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ysmv7_2_8_1

MAINTAINER=	vampiro@rootshell.ru

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=      yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		CFLAGS="-DYSM_USE_ICONV ${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS} -lcipher -L${LOCALBASE}/lib -liconv"

MAN1=		ysm.1

.include <bsd.port.mk>
