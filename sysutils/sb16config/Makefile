# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sb16config
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.granch.ru/pub/drivers/sbni16/freebsd/sb16config/
DISTFILES=	sb16config.c.gz sb16config.8.gz
EXTRACT_ONLY=

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Configuration utility for Granch SBNI16-SHDSL PCI modems

BROKEN=		unfetchable

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/sb16config \
		man/man8/sb16config.8.gz

post-extract:
.for _i in ${DISTFILES}
	@${GZCAT} ${DISTDIR}/${_i} >${WRKSRC}/${_i:R}
.endfor

.include <bsd.port.mk>
