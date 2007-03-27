# New ports collection makefile for:	libpathan
# Date created:				Nov 4 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	libpathan
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/pathan-2.0.0/
DISTNAME=	${PORTNAME}-${PORTVERSION}beta-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project

LIB_DEPENDS=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/textproc/xerces-c2:extract

USE_BISON=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}beta
USE_LDCONFIG=	yes
XERCESCROOT=	`cd ${PORTSDIR}/textproc/xerces-c2; ${MAKE} -V WRKSRC`
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	XERCESCROOT=${XERCESCROOT}
CONFIGURE_SCRIPT=	runConfigure
CONFIGURE_ARGS+=	--disable-static

PATHAN_LIB_VERSION=	3
PLIST_SUB+=	PATHAN_LIB_VERSION=${PATHAN_LIB_VERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|LIBS="-lpthread|LIBS="${PTHREAD_LIBS}|g ; s|echo aout|echo elf|' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|targetoptions="-O2"|targetoptions="${CFLAGS}"|g' \
			${WRKSRC}/runConfigure
	${FIND} ${WRKSRC}/include/pathan -name "*.orig" -delete

.include <bsd.port.post.mk>
