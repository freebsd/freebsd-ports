PORTNAME=	jsch
PORTVERSION=	0.1.55
PORTREVISION=	1
CATEGORIES=	net java security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Java implementation of SSH2
WWW=		http://www.jcraft.com/jsch

LICENSE=	BSD3CLAUSE

USES=		cpe java:ant,run zip
CPE_VENDOR=	jcraft

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
