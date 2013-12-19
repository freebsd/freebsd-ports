# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=		shrinksafe
PORTVERSION=		1.9.0
CATEGORIES=		www java
MASTER_SITES=		http://download.dojotoolkit.org/release-${PORTVERSION}/ \
			LOCAL/glarkin
PKGNAMEPREFIX=		dojo-
DISTNAME=		${PKGNAMEPREFIX}release-${PORTVERSION}-${PORTNAME}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		JavaScript code compressor

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	bin/${PKGNAMEPREFIX}${PORTNAME} %%DATADIR%%/shrinksafe.jar \
		%%DATADIR%%/js.jar
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	${PKGNAMEPREFIX}${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${INSTALL} -d ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/shrinksafe.jar ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/js.jar ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME} ${PREFIX}/bin
	@${CAT} pkg-message

.include <bsd.port.post.mk>
