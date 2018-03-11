# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_rpaf
PORTVERSION=	0.8.4
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMESUFFIX=	2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Make proxied requests appear with client IP

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	gnif

DOCS=	README.md

USES=		apache:2.2+
AP_FAST_BUILD=	yes
SHORTMODNAME=	rpaf

SRC_FILE=	mod_rpaf.c

APMOD_FILE=	200_mod_rpaf.conf.sample
PLIST_SUB+=	APMOD_FILE=${APMOD_FILE}
PLIST_FILES=	@sample\ %%APACHEETCDIR%%/modules.d/200_${PORTNAME}.conf.sample \
		%%APACHEMODDIR%%/${PORTNAME}.so
SUB_FILES=	${APMOD_FILE}

PORTDOCS=	README.md

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
