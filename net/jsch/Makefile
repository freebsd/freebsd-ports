PORTNAME=	jsch
PORTVERSION=	0.1.55
CATEGORIES=	net java security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Java implementation of SSH2

LICENSE=	BSD3CLAUSE

USES=		cpe zip
CPE_VENDOR=	jcraft
USE_JAVA=	yes
USE_ANT=	yes

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
