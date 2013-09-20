# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	cyr-rfx-${CYR_RFX_ENCODING}
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11-fonts ukrainian russian
MASTER_SITES=	ftp://ftp.ptc.spbu.ru/mirror/ftp.inp.nsk.su/%SUBDIR%/ \
		ftp://ftp.inp.nsk.su/%SUBDIR%/
MASTER_SITE_SUBDIR=	pub/BINP/X11/fonts/cyr-rfx/srctgz
EXTRACT_SUFX=	.bdfs.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Cyrillic X11 bitmap fonts from CYR-RFX project

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		fmake
USE_XORG=	x11

# See WWW for other available encodings
CYR_RFX_ENCODING?=	koi8-o

WRKSRC=		${WRKDIR}/${CYR_RFX_ENCODING}
MAKEFILE=	${FILESDIR}/Makefile.bdf2pcf
INST_DIR=	"lib/X11/fonts/${PORTNAME}"
MAKE_ENV+=	INST_DIR="${LOCALBASE}/${INST_DIR}" MKDIR="${MKDIR}"
PLIST_SUB+=	INST_DIR="${INST_DIR}"

NO_STAGE=	yes
post-install:
	@${SED} -e 's,/usr/X11R6,${LOCALBASE},g' -e \
		's,koi8-o,${CYR_RFX_ENCODING},g' < ${PKGMESSAGE}

.include <bsd.port.mk>
