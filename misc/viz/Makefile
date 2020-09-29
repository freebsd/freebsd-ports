# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	viz
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	LOCAL/fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert invisible (binary) characters to a visible form

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/Copying

USES=		tar:tgz

MAKE_ARGS=	CC="${CC}" DEFS="${CFLAGS}"

PLIST_FILES=	bin/viz bin/inviz man/man1/viz.1.gz man/man1/inviz.1.gz

do-install:
.for f in viz inviz
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
