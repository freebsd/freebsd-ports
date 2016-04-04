# Created by: arved
# $FreeBSD$

PORTNAME=	llgal
PORTVERSION=	0.13.17
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://download.gna.org/llgal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line online gallery generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-URI>=0:net/p5-URI \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool
RUN_DEPENDS=	p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-URI>=0:net/p5-URI \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool \
		convert:graphics/ImageMagick

USES=		gettext perl5 gmake tar:bzip2 shebangfix
SHEBANG_FILES=	llgal.in
USE_PERL5=	run
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s,^PREFIX,#PREFIX," ${WRKSRC}/Makefile

post-configure:
	${SED} -e "s,@VERSION@,${PORTVERSION}," < ${WRKSRC}/lib/Makefile.PL.in > ${WRKSRC}/lib/Makefile.PL
	cd ${WRKSRC}/lib; ${PERL} Makefile.PL
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install//' ${WRKSRC}/lib/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/llgal.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/llgalrc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/doc/*.html \
		${WRKSRC}/doc/llgalrc ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} examples ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
