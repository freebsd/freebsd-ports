# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdfoutline
PORTVERSION=	5.3
DISTVERSIONPREFIX=	release/
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add outlines to PDF files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Locale-libintl>=0:devel/p5-Locale-libintl \
		p5-PDF-API2>=0:textproc/p5-PDF-API2

USES=		perl5 shebangfix
USE_PERL5=	run

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pdfoutline \
		man/man1/pdfoutline.1.gz

GH_ACCOUNT=	eugmes
GH_PROJECT=	fntsample
USE_GITHUB=	yes

SHEBANG_FILES=	pdfoutline.pl

post-patch:
	@${SED} -e 's|@CMAKE_PROJECT_NAME@|fntsample|; s|@CMAKE_INSTALL_FULL_LOCALEDIR@|${LOCALBASE}/share/locale|' ${WRKSRC}/pdfoutline.pl > ${WRKSRC}/pdfoutline
	@${SED} -e 's|@DATE@|2018-12-26|' ${WRKSRC}/pdfoutline.1.in > ${WRKSRC}/pdfoutline.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdfoutline ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pdfoutline.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
