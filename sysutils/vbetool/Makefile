# Ports collection makefile for:  vbetool
# Date created:                   2008-12-05
# Whom:                           Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vbetool
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.codon.org.uk/~mjg59/vbetool/download/	\
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkim
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	An application for executing video card BIOS code

LIB_DEPENDS=	pci.2:${PORTSDIR}/devel/libpci	\
		x86.1:${PORTSDIR}/devel/libx86

PLIST_FILES=	sbin/vbetool

MAN1=		vbetool.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x86emu
CFLAGS+=	-I${PREFIX}/include -L${PREFIX}/lib

.include <bsd.port.mk>
