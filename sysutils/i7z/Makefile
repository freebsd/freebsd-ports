# $FreeBSD$

PORTNAME=	i7z
PORTVERSION=	0.27.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	zont@FreeBSD.org
COMMENT=	Thermal and C-state reporting utility for Intel-Core-i CPUs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable (google code has gone away)

USES=		gmake
USE_GCC=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

ONLY_FOR_ARCHS=	i386 amd64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.man \
		${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
