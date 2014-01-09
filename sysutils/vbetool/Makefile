# Created by: Jung-uk Kim <jkim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vbetool
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.codon.org.uk/~mjg59/vbetool/download/	\
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	An application for executing video card BIOS code

LICENSE=	GPLv2

LIB_DEPENDS=	libpci.so:${PORTSDIR}/devel/libpci \
		libx86.so:${PORTSDIR}/devel/libx86

PLIST_FILES=	man/man1/vbetool.1.gz \
		sbin/vbetool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x86emu
CFLAGS+=	-I${PREFIX}/include -L${PREFIX}/lib

.include <bsd.port.mk>
