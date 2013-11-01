# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook2odf
PORTVERSION=	0.244
CATEGORIES=	textproc perl5
MASTER_SITES=	http://open.comsultia.com/docbook2odf/dwn/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Convert docbook document to Oasis Open Document

LICENSE=	GPLv2

LIB_DEPENDS=	libsablot.so:${PORTSDIR}/textproc/sablotron \
		libxslt.so:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		zip:${PORTSDIR}/archivers/zip \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip

USES=		desktop-file-utils perl5 shebangfix
SHEBANG_FILES=	utils/maketests utils/${PORTNAME}
USE_PERL5=	run
NO_BUILD=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/tests/tests/docbook-43.001.xml
	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.cvsignore" -delete

do-install:
	${LN} -sf ${DATADIR}/utils/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "tests utils xsl" ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/bindings/desktop/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${LN} -sf ${EXAMPLESDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
