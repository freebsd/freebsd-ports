# ex:ts=8
# Ports collection makefile for:	libfame
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libfame
PORTVERSION=	0.8.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fame

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

MAN3=	fame_close.3 fame_encode_frame.3 fame_get_object.3 fame_init.3 \
	fame_open.3 fame_register.3 fame_unregister.3 fame_encode_slice.3 \
	fame_start_frame.3 fame_end_frame.3

.include <bsd.port.mk>
