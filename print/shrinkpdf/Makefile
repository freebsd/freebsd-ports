PORTNAME=		shrinkpdf
PORTVERSION=		1.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
PORTEPOCH=		1
CATEGORIES=		print graphics

MAINTAINER=		grembo@FreeBSD.org
COMMENT=		Simple wrapper around Ghostscript to reduce the file size of PDFs
WWW=		https://github.com/aklomp/shrinkpdf

LICENSE=		BSD3CLAUSE

USES=			ghostscript:run
USE_GITHUB=		yes
GH_ACCOUNT=		aklomp
SUB_FILES=		${PORTNAME}.1

NO_BUILD=		yes
NO_ARCH=		yes

PLIST_FILES=		bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/shrinkpdf.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
