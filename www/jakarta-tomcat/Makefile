# New ports collection makefile for:	jakarta-tomcat
# Date created:		20 Oct 2000
# Whom:			des
#
# $FreeBSD$
#

PORTNAME=	jakarta-tomcat
PORTVERSION=	3.1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/tomcat/release/v${PORTVERSION}/bin/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	jakarta/tomcat/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	pinstall:${PORTSDIR}/devel/pinstall
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk

NO_BUILD=	yes

do-install:
	@${LN} -fs ${WRKSRC} ${WRKDIR}/tomcat
	@pinstall -v -d ${WRKDIR}

.include <bsd.port.mk>
