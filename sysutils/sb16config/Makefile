# New ports collection makefile for:	smbfs
# Date created:				2th Dec 2000
# Whom:					Jaedoc Lee <tokky@fdns.org>
#
# $FreeBSD$
#

PORTNAME=	sb16config
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.granch.ru/pub/drivers/sbni16/freebsd/sb16config/
DISTFILES=	sb16config.c.gz sb16config.8.gz
EXTRACT_ONLY=

MAINTAINER=	fjoe@freebsd.org
COMMENT=	Configuration utility for Granch SBNI16-SHDSL PCI modems

NO_WRKSUBDIR=	yes
MAN8=		sb16config.8
MANCOMPRESSED=	yes

post-extract:
.for _i in ${DISTFILES}
	@${GZCAT} ${DISTDIR}/${_i} >${WRKDIR}/${_i:R}
.endfor
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
