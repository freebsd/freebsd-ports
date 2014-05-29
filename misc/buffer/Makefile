# Created by: Joao Carlos Mendes Luis <jonny@jonny.eng.br>
# $FreeBSD$

PORTNAME=	buffer
PORTVERSION=	1.19
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://www.mondorescue.org/download/MondoCD/TGZS/
MASTER_SITE_SUBDIR=	distfiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Buffer sporadic I/O for faster tape and pipe throughput

PLIST_FILES=	bin/buffer \
		man/man1/buffer.1.gz

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^(CC[[:space:]]*=).*$$|\1${CC}|' \
		-e 's|^(CFLAGS[[:space:]]*=).*$$|\1${CFLAGS}|' \
		-e 's|^(INSTBIN[[:space:]]*=).*$$|\1${STAGEDIR}${PREFIX}/bin|' \
		-e 's|^(INSTMAN[[:space:]]*=).*$$|\1${STAGEDIR}${MAN1PREFIX}/man/man1|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
