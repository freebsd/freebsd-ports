# New ports collection makefile for:	unidesc
# Date created:		Sun 15 May 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	unidesc
PORTVERSION=	2.17
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Unicode Description Utilities

RUN_DEPENDS=	ascii2binary:${PORTSDIR}/converters/ascii2binary

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"		\
		LIBS="-lintl"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

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
