PORTNAME=	buffer
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	GENTOO \
		http://www.mondorescue.org/download/MondoCD/TGZS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Buffer sporadic I/O for faster tape and pipe throughput

USES=		tar:tgz
PLIST_FILES=	bin/buffer \
		share/man/man1/buffer.1.gz
CFLAGS+=	-D_WANT_SEMUN
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		INSTBIN="${STAGEDIR}${PREFIX}/bin" \
		INSTMAN="${STAGEDIR}${PREFIX}/share/man/man1"

.include <bsd.port.mk>
