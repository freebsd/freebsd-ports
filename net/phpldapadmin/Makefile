# New ports collection makefile for: phpLDAPadmin
# Date created:		30 Apr 2004
# Whom:			Matthew Seaman
#
# $FreeBSD$
#

PORTNAME=	phpldapadmin
PORTVERSION=	0.9.4b
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpldapadmin

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to administer LDAP servers over the web

USE_PHP=	yes
WANT_PHP_WEB=	yes
NO_BUILD=	yes

WWWDIR?=	www/${PORTNAME}

MSG_SKEL=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/plist
PLIST_SUB+=	WWWDIR=${WWWDIR}

.SILENT:

post-patch:
	${RM} -f ${PLIST}
	cd ${WRKSRC} ; \
	${FIND} . ! -type d ! -name .cvsignore | ${SORT} | \
	    ${SED} "s,^.,%%WWWDIR%%," >${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | \
	    ${SED} "s,^.,@dirrm %%WWWDIR%%," >>${PLIST}
	${SED} -e 's,%%WWWDIR%%,${WWWDIR},g' \
	       -e 's,%%PREFIX%%,${PREFIX},g' ${MSG_SKEL} > ${PKGMESSAGE}

do-install:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore  ) ; do \
	    dst=${PREFIX}/${WWWDIR}$${src#.} ; \
	    if ${TEST} -d $$src ; then \
	        ${MKDIR} $$dst ; \
	    else \
	        ${INSTALL_DATA} $$src $$dst ; \
	    fi \
	done

post-install:
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.mk>
