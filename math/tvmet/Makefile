# ex:ts=8
# Ports collection makefile for:	tvmet
# Date created:			Jul 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tvmet
PORTVERSION=	1.7.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny Vector and Matrix template library

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		tvmet-config.1

.if defined(WITH_CPPUNIT)
LIB_DEPENDS+=	cppunit-1.10.2:${PORTSDIR}/devel/cppunit
CONFIGURE_ARGS+=	--with-cppunit-prefix=${LOCALBASE}
.else
CONFIGURE_ENV+=	ac_cv_path_CPPUNIT_CONFIG=no
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in dox cc css h png
	${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for ext in cc
	${INSTALL_DATA} ${WRKSRC}/examples/*.${ext} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
