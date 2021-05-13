# Created by: Danilo Egea Gondolfo <danilogondolfo@gmail.com>

PORTNAME=	yap
PORTVERSION=	6.2.2
PORTREVISION=	10
CATEGORIES=	lang
MASTER_SITES=	https://mirrors.dotsrc.org/mirrors/exherbo/	\
		http://ftp.lyx.org/pub/minix/distfiles/backup/	\
		http://tenampak.izt.uam.mx/programas/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance Prolog compiler

BROKEN_riscv64=		fails to build: procedure chr_translate/2 is undefined, called from context  prolog:once/1

LIB_DEPENDS=	libgmp.so:math/gmp

PORTSCOUT=	limit:^6\.2\.

USES=		gmake localbase readline
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-max-performance \
		--disable-myddas

DATADIR=	${PREFIX}/share/Yap

post-configure:
	# prevent the instalation of three docs files
	${REINPLACE_CMD} -e '559,562d' ${WRKSRC}/Makefile

.include <bsd.port.mk>
