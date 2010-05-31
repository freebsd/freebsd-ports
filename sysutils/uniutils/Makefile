# New ports collection makefile for:	unidesc
# Date created:		Sun 15 May 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	uniutils
PORTVERSION=	2.27
PORTREVISION=	1
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Description Utilities

RUN_DEPENDS=	ascii2binary:${PORTSDIR}/converters/ascii2binary

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"		\
		LIBS="-lintl"
USE_GETTEXT=	yes

TESTFILES=	Test1.ann Test1.u Test2.ann Test2.u Test3.ann Test3.u	\
		Test4.ann Test4.u Test5.ann Test5.u
PORTDOCS=	AUTHORS NEWS README

MAN1=		ExplicateUTF8.1 unidesc.1 unifuzz.1 unihist.1 uniname.1	\
		unireverse.1

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|TestData|${EXAMPLESDIR}|' ${WRKSRC}/README

regression-test:
	(cd ${WRKSRC} &&		\
	./unidesc TestData/Test1.u &&	\
	./uniname TestData/Test1.ann)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${TESTFILES:S|^|${WRKSRC}/TestData/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
