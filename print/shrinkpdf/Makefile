PORTNAME=		shrinkpdf
PORTVERSION=		1.1
DISTVERSIONPREFIX=	v
PORTEPOCH=		1
CATEGORIES=		print graphics

MAINTAINER=		grembo@FreeBSD.org
COMMENT=		Simple wrapper around Ghostscript to reduce the file size of PDFs

LICENSE=		BSD3CLAUSE

USES=			ghostscript:run
USE_GITHUB=		yes
GH_ACCOUNT=		aklomp
SUB_FILES=		${PORTNAME}.1

NO_BUILD=		yes
NO_ARCH=		yes

PLIST_FILES=		bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/shrinkpdf.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
