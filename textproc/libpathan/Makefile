# New ports collection makefile for:	libpathan
# Date created:				Nov 4 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	libpathan
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/pathan-1.2r2/
DISTNAME=	${PORTNAME}-${PORTVERSION}-2-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project

LIB_DEPENDS=	xerces-c.23:${PORTSDIR}/textproc/xerces-c2
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/textproc/xerces-c2:extract

USE_BISON=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALLS_SHLIB=	yes
XERCESCROOT=	`cd ${PORTSDIR}/textproc/xerces-c2; ${MAKE} -V WRKSRC`
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	XERCESCROOT=${XERCESCROOT}
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ARGS+=	--disable-static
USE_REINPLACE=	yes

PATHAN_LIB_VERSION=	2
PLIST_SUB+=	PATHAN_LIB_VERSION=${PATHAN_LIB_VERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|LIBS="-lpthread|LIBS="${PTHREAD_LIBS}|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
			${WRKSRC}/examples/tests/Makefile
	@${REINPLACE_CMD} -e 's|targetoptions="-O2"|targetoptions="${CFLAGS}"|g' \
			${WRKSRC}/runConfigure

.if !defined(NO_EXAMPLES)
PLIST_SUB+=	NO_EXAMPLES=""
.else
PLIST_SUB+=	NO_EXAMPLES="@comment "
.endif

EXAMPLEDIR?=	${PREFIX}/share/examples/pathan
post-install:
.if !defined(NO_EXAMPLES)
	@${MKDIR} ${EXAMPLEDIR}
.for i in basic common xgrep timing tests Makefile
	@${CP} -r ${WRKSRC}/examples/$i ${EXAMPLEDIR}
.endfor
.endif

.include <bsd.port.post.mk>
