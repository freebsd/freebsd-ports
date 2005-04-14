# New ports collection makefile for:   openradius
# Date created:        23 May 2003
# Whom:                Adam Jette <jettea46@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	openradius
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.xs4all.nl/~evbergen/openradius/download/ \
		http://www.mirrors.wiretapped.net/security/authentication/radius/openradius/

MAINTAINER=	jettea46@yahoo.com
COMMENT=	A RADIUS server with some actual documentation

LOGFILE?=	/var/log/openradius.log

CONFLICTS=	freeradius-0.* gnu-radius-1.* radiusd-cistron-1.*

CC?=		gcc
CXX?=		g++
USE_GMAKE=	yes

OPTIONS=	LDAP	"With LDAP user database" off

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_OPENLDAP=	YES
PLIST_SUB+=	LDAP=""
SCRIPTS_ENV+=	USE_LDAP=yes
.else
PLIST_SUB+=	LDAP="@comment "
.endif

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%LOGFILE%%|${LOGFILE}|g" \
		< ${FILESDIR}/openradiusd.sh > ${WRKDIR}/openradiusd.sh

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/accounts
	${INSTALL_MAN} ${WRKSRC}/doc/async-iface-notes ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/language.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/module-interface.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/note-struct-ownership ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/using-openradius.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/behaviour.sample-ldap ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/behaviour.sample-ldap-authbind ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/behaviour.sample-mysql ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/behaviour.sample-postgres ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/behaviour.sample-unixpass ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/behaviour.sample-usersfile ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/behaviour.sample-usersfile-longpass ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/configuration.sample-ldap ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/configuration.sample-ldap-authbind ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/configuration.sample-mysql ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/configuration.sample-postgres ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/configuration.sample-unixpass ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/configuration.sample-usersfile ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/redhat-sysv-init-script ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/examples/accounts/README ${EXAMPLESDIR}/accounts
	${INSTALL_MAN} ${WRKSRC}/examples/accounts/accounts.mysql ${EXAMPLESDIR}/accounts
	${INSTALL_MAN} ${WRKSRC}/examples/accounts/behaviour ${EXAMPLESDIR}/accounts
	${INSTALL_MAN} ${WRKSRC}/examples/accounts/configuration ${EXAMPLESDIR}/accounts
.endif
# Configuration, copy over to sample files
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for FILE in dictionary behaviour configuration
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} \
		${PREFIX}/etc/${PORTNAME}/${FILE}.sample
.endfor
# Copy over legacy config files to sample
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/legacy
.for FILE in clients nases realms users
	${INSTALL} -m 0600 ${WRKSRC}/etc/legacy/${FILE} \
		${PREFIX}/etc/${PORTNAME}/legacy/${FILE}.sample
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/openradiusd.sh ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
