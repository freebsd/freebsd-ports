# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	cyr-rfx-${CYR_RFX_ENCODING}
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	x11-fonts ukrainian russian
MASTER_SITES=	ftp://ftp.ptc.spbu.ru/mirror/ftp.inp.nsk.su/%SUBDIR%/ \
		ftp://ftp.inp.nsk.su/%SUBDIR%/
MASTER_SITE_SUBDIR=	pub/BINP/X11/fonts/cyr-rfx/srctgz
EXTRACT_SUFX=	.bdfs.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Cyrillic X11 bitmap fonts from CYR-RFX project

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontdir:x11-fonts/mkfontdir

USES=		fonts
USE_XORG=	x11

CYR_RFX_ENCODING?=	koi8-o

WRKSRC=		${WRKDIR}/${CYR_RFX_ENCODING}
MAKEFILE=	${FILESDIR}/Makefile.bdf2pcf
MAKE_ENV+=	INST_DIR="${STAGEDIR}${FONTSDIR}" MKDIR="${MKDIR}"

SUB_FILES=	pkg-message

.include <bsd.port.mk>
