# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	uniutils
PORTVERSION=	2.27
PORTREVISION=	1
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Description Utilities

LICENSE=	GPLv3

RUN_DEPENDS=	ascii2binary:${PORTSDIR}/converters/ascii2binary

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl
USES=		gettext

TESTFILES=	Test1.ann Test1.u Test2.ann Test2.u Test3.ann Test3.u	\
		Test4.ann Test4.u Test5.ann Test5.u
PORTDOCS=	AUTHORS NEWS README

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|TestData|${EXAMPLESDIR}|' ${WRKSRC}/README

regression-test:
	(cd ${WRKSRC} &&		\
	./unidesc TestData/Test1.u &&	\
	./uniname TestData/Test1.ann)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${TESTFILES:S|^|${WRKSRC}/TestData/|} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
