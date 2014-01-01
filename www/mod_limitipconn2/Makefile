# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	mod_limitipconn
PORTVERSION=	0.23
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://dominia.org/djao/limit/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2
DIST_SUBDIR=	apache2

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Allows you to limit the number of simultaneous connexions

LICENSE=	APACHE20

USE_APACHE=	22
USE_BZIP2=	yes

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PLIST_FILES+=	${APACHEMODDIR}/${PORTNAME}.so

PORTDOCS=	ChangeLog INSTALL README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
