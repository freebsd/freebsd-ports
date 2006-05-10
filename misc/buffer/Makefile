# New ports collection makefile for:	buffer
# Date created:         23 February 1998
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	buffer
PORTVERSION=	1.19
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://www.mondorescue.org/download/MondoCD/TGZS/
MASTER_SITE_SUBDIR=	distfiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	jonny@jonny.eng.br
COMMENT=	Buffer sporadic I/O for faster tape and pipe throughput

MAN1=		buffer.1
PLIST_FILES=	bin/buffer

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^(CC[[:space:]]*=).*$$|\1${CC}|' \
		-e 's|^(CFLAGS[[:space:]]*=).*$$|\1${CFLAGS}|' \
		-e 's|^(INSTBIN[[:space:]]*=).*$$|\1${PREFIX}/bin|' \
		-e 's|^(INSTMAN[[:space:]]*=).*$$|\1${MAN1PREFIX}/man/man1|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
