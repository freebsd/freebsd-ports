# New ports collection makefile for:	unidesc
# Date created:		Sun 15 May 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	unidesc
PORTVERSION=	2.13
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.cis.upenn.edu/~wjposer/.downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Description Utilities

USE_GETTEXT=	yes
USE_REINPLACE=	yes

TESTFILES=	TestData/Test1.ann TestData/Test1.u TestData/Test2.ann	\
		TestData/Test2.u TestData/Test3.ann TestData/Test3.u	\
		TestData/Test4.ann TestData/Test4.u
DEMOS=		demo.jpg demo.u demo32.u
PORTDOCS=	README

MAN1=		unidesc.1 uniname.1 ExplicateUTF8.1 unihist.1

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|;s|%%LOCALBASE%%|${LOCALBASE}|'	\
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|TestData|${EXAMPLESDIR}|' ${WRKSRC}/README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	${INSTALL_DATA} ${TESTFILES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DEMOS:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
