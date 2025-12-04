PORTNAME=	jsch
PORTVERSION=	0.1.55
PORTREVISION=	2
CATEGORIES=	net java security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Java implementation of SSH2
WWW=		http://www.jcraft.com/jsch

LICENSE=	BSD3CLAUSE

DEPRECATED=	Upstream website does not exist. No ports depend on this. It does not compile on jdk21. See also: https://github.com/mwiede/jsch
EXPIRATION_DATE=	2026-01-31

USES=		cpe java:ant,run zip
CPE_VENDOR=	jcraft

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
