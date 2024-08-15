PORTNAME=	uni2ascii
DISTVERSION=	4.20
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert between UTF-8 Unicode and 7-bit ASCII equivalents
WWW=		https://billposer.org/Software/uni2ascii.html

LICENSE=	GPLv3

USES=		tar:bzip2
GNU_CONFIGURE=	yes

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/ascii2uni \
		bin/uni2ascii \
		share/man/man1/ascii2uni.1.gz \
		share/man/man1/uni2ascii.1.gz

do-install:
.for f in ${PORTNAME} ascii2uni
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
