PORTNAME=	payara
PORTVERSION=	5.2020.4
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/fish/payara/distributions/${PORTNAME}/${PORTVERSION}/
MAINTAINER=	dmytro@posteo.net
COMMENT=	Jakarta EE application server derived from GlassFish Server Open Source Edition

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/payara5
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}
VARMAIN=	/var/${PORTNAME}
VARDIR=		/var/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE?=	${WRKDIR}/pkg-message

PLIST_SUB+=	VARDIR=${VARDIR}
PLIST_SUB+=	VARMAIN=${VARMAIN}

# Since we USE_JAVA, we propagate the received JAVA_HOME variable to the
# template files, since it is used by the rc script.
SUB_LIST=	PAYARAVERSION=${PORTVERSION} \
		JAVA_HOME=${JAVA_HOME}

DOWNLOAD_URL=	https://repo1.maven.org/maven2/fish/payara/distributions/${PORTNAME}/${PORTVERSION}/

USE_RC_SUBR=	payara

USERS=		payara
GROUPS=		payara

GLASSFISH_BIN_FILES=	appclient asadmin capture-schema jspc package-appclient schemagen startserv stopserv wscompile wsdeploy wsgen wsimport xjc

.include <bsd.port.pre.mk>

do-install:
	@${SED} "s|%%VARDIR%%|${VARDIR}|g" ${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message
	@${MKDIR} ${STAGEDIR}${VARDIR}/prefs
	@${RM} ${WRKSRC}/bin/letsencrypt.py
	@${FIND} ${WRKSRC} -name '*.bat' -delete
	@${FIND} ${WRKSRC} -name '*.exe' -delete
	@${FIND} ${WRKSRC} -name '*.dll' -delete
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	@${FIND} ${STAGEDIR}${DATADIR}/glassfish/domains -path "*/config/*" -type f -exec ${MV} {} {}.sample \;
	@${MV} ${STAGEDIR}${DATADIR}/glassfish/domains ${STAGEDIR}${VARDIR}/domains
	@${RLN} ${STAGEDIR}${VARDIR}/domains ${STAGEDIR}${DATADIR}/glassfish/domains
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/*
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/mq/bin/*
.for x in ${GLASSFISH_BIN_FILES}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/glassfish/bin/${x}
.endfor

.include <bsd.port.post.mk>
