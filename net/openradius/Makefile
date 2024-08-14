PORTNAME=	openradius
DISTVERSION=	0.9.14
CATEGORIES=	net
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	RADIUS server with some actual documentation
WWW=		https://codeberg.org/BSDforge/${PORTNAME}/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake shebangfix
USE_RC_SUBR=	openradius
SHEBANG_FILES=	modules/ascfile/ascfile modules/debug/debug \
		modules/memory/memory modules/radsql/radsql \
		modules/unixpasswd/unixpasswd
LOGFILE?=	/var/log/openradius/openradius.log

MAKE_ENV=	INST_PREFIX=${STAGEDIR}
CONFLICTS=	freeradius freeradius-mysql gnu-radius radiusd-cistron

CC?=		gcc
CXX?=		g++

SUB_LIST=	LOGFILE="${LOGFILE}"

OPTIONS_DEFINE=		DOCS EXAMPLES LDAP
OPTIONS_DEFAULT=	DOCS EXAMPLES

DOCS_DESC=	Install documentstion
EXAMPLES_DESC=	Include examples
LDAP_DESC=	Install LDAP support

LDAP_USES+=		ldap
LDAP_PLIST_SUB+=	LDAP=""
LDAP_PLIST_SUB_OFF+=	LDAP="@comment"
LDAP_SCRIPTS_ENV+=	USE_LDAP=yes

post-extract:
	${MV} ${WRKDIR}/${PORTNAME} ${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/accounts
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
	${STAGEDIR}${EXAMPLESDIR} "! -name redhat-sysv-init-script")
# Configuration, copy over to sample files
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for FILE in dictionary
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} \
		${STAGEDIR}${ETCDIR}/${FILE}.sample
.endfor
# Copy over legacy config files to sample
	${MKDIR} ${STAGEDIR}${ETCDIR}/legacy
.for FILE in clients nases realms users
	${INSTALL} -m 0600 ${WRKSRC}/etc/legacy/${FILE} \
		${STAGEDIR}${ETCDIR}/legacy/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}/modules
.for FILE in radldap.attrmap
	${INSTALL} -m 0600 ${WRKSRC}/etc/modules/${FILE} \
		${STAGEDIR}${ETCDIR}/modules/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}/subdicts
.for FILE in dict.*
	${INSTALL} -m 0600 ${WRKSRC}/etc/subdicts/${FILE} \
		${STAGEDIR}${ETCDIR}/subdicts/
.endfor

.include <bsd.port.mk>
