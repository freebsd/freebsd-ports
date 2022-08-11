PORTNAME=	pdfoutline
PORTVERSION=	5.4
DISTVERSIONPREFIX=	release/
PORTREVISION=	2
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

GH_ACCOUNT=	eugmes
GH_PROJECT=	fntsample
USE_GITHUB=	yes

SHEBANG_FILES=	scripts/*.pl

post-patch:
.for file in pdf-extract-outline pdfoutline
	@${SED} -e 's|@CMAKE_PROJECT_NAME@|fntsample|; s|@CMAKE_INSTALL_FULL_LOCALEDIR@|${LOCALBASE}/share/locale|' ${WRKSRC}/scripts/${file}.pl > ${WRKSRC}/${file}
	@${SED} -e 's|@DATE@|2021-08-01|; s|@CMAKE_PROJECT_VERSION@|${PORTVERSION}|; s|@CMAKE_PROJECT_NAME@|fntsample|; s|@CMAKE_PROJECT_HOMEPAGE_URL@|https://github.com/eugmes/fntsample|' ${WRKSRC}/scripts/${file}.1.in > ${WRKSRC}/${file}.1
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdf-extract-outline ${WRKSRC}/pdfoutline ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pdf-extract-outline.1 ${WRKSRC}/pdfoutline.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
