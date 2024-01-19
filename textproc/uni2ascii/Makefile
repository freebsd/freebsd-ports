PORTNAME=	uni2ascii
PORTVERSION=	4.18
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert between UTF-8 Unicode and 7-bit ASCII equivalents
WWW=		http://freecode.com/projects/uni2ascii/

LICENSE=	GPLv3

USES=		tar:bzip2
GNU_CONFIGURE=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/uni2ascii bin/ascii2uni share/man/man1/uni2ascii.1.gz \
		share/man/man1/ascii2uni.1.gz

do-install:
.for f in ${PORTNAME} ascii2uni
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
