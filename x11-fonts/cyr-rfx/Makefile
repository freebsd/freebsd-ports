# New ports collection makefile for:    cyr-rfx
# Date created:				Jan 20, 2003
# Whom:					mi@aldan.algebra.com
#
# $NetBSD: Makefile.common,v 1.2 2002/07/13 15:43:36 wiz Exp $
# $FreeBSD$

PORTNAME=	cyr-rfx-${CYR_RFX_ENCODING}
PORTVERSION=	1.1
CATEGORIES=	x11-fonts ukrainian russian
MASTER_SITES=	ftp://ftp.ptc.spbu.ru/mirror/ftp.inp.nsk.su/%SUBDIR%/ \
		ftp://ftp.inp.nsk.su/%SUBDIR%/
MASTER_SITE_SUBDIR=	pub/BINP/X11/fonts/cyr-rfx/srctgz
EXTRACT_SUFX=	.bdfs.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Cyrillic X11 bitmap fonts from CYR-RFX project

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT} \
		mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes

# See WWW for other available encodings
CYR_RFX_ENCODING?=	koi8-o

WRKSRC=		${WRKDIR}/${CYR_RFX_ENCODING}
NCPUS!=		/sbin/sysctl -n hw.ncpu 2> /dev/null || echo 1
MAKE_ARGS+=	-j ${NCPUS}
MAKEFILE=	${FILESDIR}/Makefile.bdf2pcf
INST_DIR=	"lib/X11/fonts/${PORTNAME}"
MAKE_ENV+=	INST_DIR="${X11BASE}/${INST_DIR}" MKDIR="${MKDIR}"
PLIST_SUB+=	INST_DIR="${INST_DIR}"

post-install:
	@${SED} -e 's,/usr/X11R6,${X11BASE},g' -e \
		's,koi8-o,${CYR_RFX_ENCODING},g' < ${PKGMESSAGE}

.include <bsd.port.mk>
