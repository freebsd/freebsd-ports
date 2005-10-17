# New ports collection makefile for:	ldapscripts
# Date created:		Sat Oct 01 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	ldapscripts
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://contribs.martymac.com/ldapscripts/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Scripts to manage posix accounts in an OpenLDAP directory

RUN_DEPENDS=	ldapadd:${PORTSDIR}/net/openldap23-server \
		ldapsearch:${PORTSDIR}/net/openldap23-server \
		ldapdelete:${PORTSDIR}/net/openldap23-server \
		ldapmodify:${PORTSDIR}/net/openldap23-server \
		slappasswd:${PORTSDIR}/net/openldap23-server

USE_REINPLACE=	yes

# Change /etc to ${LOCALBASE}/etc
post-patch:
.for file in _ldapdeletemachine _ldapinit _lsldap ldapaddgroup ldapadduser ldapdeletegroup \
		ldapdeleteuserfromgroup ldapsetprimarygroup ldapaddmachine ldapaddusertogroup ldapdeleteuser \
		ldapscripts.conf runtime README CHANGELOG COPYING VERSION
	${REINPLACE_CMD} -E -e "s|/etc/ldapscripts|${LOCALBASE}/etc/ldapscripts|g" ${WRKSRC}/${file}
.endfor

# We do not use any Makefile
do-build:

# Just copy the scripts
do-install:
	${CP} ${WRKSRC}/_ldapdeletemachine ${PREFIX}/bin
	${CP} ${WRKSRC}/_ldapinit ${PREFIX}/bin
	${CP} ${WRKSRC}/_lsldap ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapaddgroup ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapadduser ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapdeletegroup ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapdeleteuserfromgroup ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapsetprimarygroup ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapaddmachine ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapaddusertogroup ${PREFIX}/bin
	${CP} ${WRKSRC}/ldapdeleteuser ${PREFIX}/bin

	${MKDIR} ${LOCALBASE}/etc/ldapscripts
	if [ -f ${LOCALBASE}/etc/ldapscripts/ldapscripts.conf ]; then \
		${CP} ${LOCALBASE}/etc/ldapscripts/ldapscripts.conf ${LOCALBASE}/etc/ldapscripts/ldapscripts.conf.old; \
	fi
	${CP} ${WRKSRC}/ldapscripts.conf ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/runtime ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/README ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/CHANGELOG ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/COPYING ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/VERSION ${LOCALBASE}/etc/ldapscripts

.include <bsd.port.mk>
