# $FreeBSD$

PORTNAME=	jtransforms
PORTVERSION=	2.4
CATEGORIES=	math java
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=jtransforms/jtransforms/${PORTVERSION}
DISTNAME=	jtransforms-${PORTVERSION}-src

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A multithreaded FFT library written in pure Java

USE_BZIP2=	yes
USE_JAVA=	1.5+
USE_ANT=	yes

WRKSRC=		${WRKDIR}/JTransforms

PLIST_FILES=	%%JAVAJARDIR%%/jtransforms.jar

do-install:
	@${INSTALL_DATA} ${WRKSRC}/jtransforms-2.4.jar ${JAVAJARDIR}/jtransforms.jar

.include <bsd.port.mk>
