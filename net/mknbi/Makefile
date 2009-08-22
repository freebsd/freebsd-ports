# New ports collection makefile for:	mknbi
# Date created:				17 Mar 2005
# Whom:					X
#
# $FreeBSD$
#

PORTNAME=	mknbi
PORTVERSION=	1.4.4
CATEGORIES=	net
MASTER_SITES=	SF/etherboot/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates tagged boot images for net/ether boot

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

MAN1=		mknbi.1 disnbi.1
.for i in	mkelf.1 mknbi-linux.1 mkelf-linux.1 \
		mknbi-rom.1 mkelf-img.1 mknbi-menu.1 mkelf-menu.1 \
		mknbi-nfl.1 mkelf-nfl.1 mknbi-dos.1 mknbi-fdos.1 mkelf-lua.1
MLINKS+=	mknbi.1 ${i}
.endfor

PORTDOCS=	COPYING README LOG spec.txt

USE_GMAKE=	yes
USE_PERL5=	yes
ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e 's,^static int terminal,int terminal,' \
		${WRKSRC}/nfl.c

.include <bsd.port.mk>
