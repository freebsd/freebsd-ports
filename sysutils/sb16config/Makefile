# New ports collection makefile for:	sb16config
# Date created:				13 Apr 2003
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sb16config
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.granch.ru/pub/drivers/sbni16/freebsd/sb16config/
DISTFILES=	sb16config.c.gz sb16config.8.gz
EXTRACT_ONLY=

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Configuration utility for Granch SBNI16-SHDSL PCI modems

NO_WRKSUBDIR=	yes
MAN8=		sb16config.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/sb16config

post-extract:
.for _i in ${DISTFILES}
	@${GZCAT} ${DISTDIR}/${_i} >${WRKDIR}/${_i:R}
.endfor
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
