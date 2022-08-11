PORTNAME=	ondir
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://swapoff.org/files/${PORTNAME}/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Automatically executes scripts as you traverse directories

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	PREFIX="${PREFIX}" \
		CC="${CC}" LD="${CC}" \
		CFLAGS="${CFLAGS} -DVERSION=\\\"${PORTVERSION}\\\" -DGLOBAL_CONF=\\\"${PREFIX}/etc/ondirrc\\\"" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
