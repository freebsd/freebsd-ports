PORTNAME=		dojo
DISTVERSION=		1.12.3
CATEGORIES=		www
MASTER_SITES=		http://download.dojotoolkit.org/release-${PORTVERSION}/
DISTNAME=		dojo-release-${PORTVERSION}

MAINTAINER=		bofh@FreeBSD.org
COMMENT=		Open-source DHTML toolkit written in JavaScript
WWW=		https://dojotoolkit.org/

LICENSE=		BSD3CLAUSE

USES=			cpe
CPE_VENDOR=		linuxfoundation

NO_ARCH=		yes
NO_BUILD=		yes
SHAREOWN=		www
SHAREGRP=		www

OPTIONS_DEFINE=		APACHE
OPTIONS_SUB=		yes

APACHE_USES=		apache:run cpe

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
CONFDIR=		${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=		${APACHEETCDIR}/Includes
PLIST_SUB+=		CONFDIR=${CONFDIR_REL}
CONF=			dojo.conf
SUB_FILES+=		pkg-message ${CONF}
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type f | ${SORT} | \
			${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

do-install-APACHE-on:
	@${MKDIR} ${STAGEDIR}${CONFDIR}
	${CP} ${WRKDIR}/${CONF} ${STAGEDIR}${CONFDIR}/dojo.conf.sample

.include <bsd.port.mk>
