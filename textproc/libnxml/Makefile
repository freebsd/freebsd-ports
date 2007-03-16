# New ports collection makefile for:	libnxml
# Date created:		2006-04-09
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	libnxml
PORTVERSION=	0.17
CATEGORIES=	textproc devel
MASTER_SITES=	http://www2.autistici.org/bakunin/libnxml/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A C library for writing XML 1.0/1.1 files or streams

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I/${LOCALBASE}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

USE_LDCONFIG=	yes

WANT_GNOME=	yes

pre-patch:
	${gnomehack_PRE_PATCH}

.include <bsd.port.mk>
