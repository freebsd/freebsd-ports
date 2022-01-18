PORTNAME=	paros
PORTVERSION=	3.2.13
PORTREVISION=	2
CATEGORIES=	www security java
MASTER_SITES=	SF/${PORTNAME}/Paros/Version%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP/HTTPS proxy for assessing web application vulnerability

DEPRECATED=	Abandonware, last release in 2006 and dead upstream
EXPIRATION_DATE=2022-03-31

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_RUN=	yes

NO_BUILD=	yes
USES=		cpe dos2unix zip
DOS2UNIX_FILES=	release.txt

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|java -jar \(paros.jar\)|cd ${DATADIR} \&\& java -jar ${DATADIR}/\1|g' \
	${WRKSRC}/startserver.sh
	${RM} ${WRKSRC}/startserver.sh.bak

do-install:
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_BIN} \* ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME} \
	"! -name startserver.sh")
	${INSTALL_SCRIPT} ${WRKSRC}/startserver.sh ${STAGEDIR}${PREFIX}/bin/paros

.include <bsd.port.mk>
