# New ports collection makefile for:	unidesc
# Date created:		Sun 15 May 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	unidesc
PORTVERSION=	2.15
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Description Utilities

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"		\
		LIBS="-lintl"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETTEXT=	yes
USE_REINPLACE=	yes

TESTFILES=	Test1.ann Test1.u Test2.ann Test2.u Test3.ann Test3.u	\
		Test4.ann Test4.u
PORTDOCS=	AUTHORS NEWS README

MAN1=		unidesc.1 uniname.1 ExplicateUTF8.1 unihist.1

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|TestData|${EXAMPLESDIR}|' ${WRKSRC}/README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	${INSTALL_DATA} ${TESTFILES:S|^|${WRKSRC}/TestData/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
