# $FreeBSD$

PORTNAME=	payara
PORTVERSION=	4.1.1.163
CATEGORIES=	www java
MASTER_SITES=	https://github.com/payara/Payara/releases/download/${PORTVERSION}/

MAINTAINER=	dmytro@posteo.net
COMMENT=	Java EE application server derived from GlassFish Server Open Source Edition

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/payara41
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}

# Since we USE_JAVA, we propagate the received JAVA_HOME variable to the
# template files, since it is used by the rc script.
SUB_LIST=	PAYARAVERSION=${PORTVERSION} \
		JAVA_HOME=${JAVA_HOME}

DOWNLOAD_URL=	https://github.com/payara/Payara/releases/download/${PORTVERSION}/

USE_RC_SUBR=	payara
GLASSFISH_BIN_FILES=	appclient asadmin capture-schema jspc package-appclient schemagen startserv stopserv wscompile wsdeploy wsgen wsimport xjc

.include <bsd.port.pre.mk>

do-install:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
	@${FIND} ${WRKSRC} -name '*.exe' -delete
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/*
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/mq/bin/*
.for x in ${GLASSFISH_BIN_FILES}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/glassfish/bin/${x}
.endfor

.include <bsd.port.post.mk>
