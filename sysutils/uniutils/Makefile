PORTNAME=	uniutils
PORTVERSION=	2.28
PORTREVISION=	1
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Description Utilities
WWW=		https://billposer.org/Software/unidesc.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ascii2binary:converters/ascii2binary

USES=		gettext localbase tar:bz2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

LIBS+=		-lintl

TESTFILES=	Test1.ann Test1.u Test2.ann Test2.u Test3.ann Test3.u	\
		Test4.ann Test4.u Test5.ann Test5.u
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|TestData|${EXAMPLESDIR}|' ${WRKSRC}/README

do-test:
	(cd ${WRKSRC} &&		\
	./unidesc TestData/Test1.u &&	\
	./uniname TestData/Test1.ann)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${TESTFILES:S|^|${WRKSRC}/TestData/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
