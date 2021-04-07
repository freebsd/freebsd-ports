PORTNAME=	shrinkpdf
PORTVERSION=	20191221
CATEGORIES=	print graphics
MASTER_SITES=	http://www.alfredklomp.com/programming/shrinkpdf/
DISTNAME=	${PORTNAME}.sh
EXTRACT_SUFX=   # none
EXTRACT_ONLY=	# none

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Simple wrapper around Ghostscript to reduce the file size of PDFs

LICENSE=	BSD3CLAUSE

USES=		ghostscript:run
SUB_FILES=	${PORTNAME}.1

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/shrinkpdf.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
