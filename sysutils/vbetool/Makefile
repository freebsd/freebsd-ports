# Created by: Jung-uk Kim <jkim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vbetool
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.codon.org.uk/~mjg59/vbetool/download/	\
		LOCAL/jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Application for executing video card BIOS code

LICENSE=	GPLv2

LIB_DEPENDS=	libpci.so:devel/libpci \
		libx86.so:devel/libx86

PLIST_FILES=	man/man1/vbetool.1.gz \
		sbin/vbetool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x86emu
CFLAGS+=	-I${PREFIX}/include -L${PREFIX}/lib

.include <bsd.port.mk>
