# New ports collection makefile for:    ldapdiff
# Date created:         15 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org)
#
# $FreeBSD$
#

PORTNAME=       ldapdiff
PORTVERSION=    0.7.0
CATEGORIES=     net
MASTER_SITES=   http://webtomware.rhoen.de/

MAINTAINER=     chris@unixpages.org

LIB_DEPENDS=    ldap.2:${PORTSDIR}/net/openldap2

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= \
				--prefix=${PREFIX} \
				--with-ldap-dir=${PREFIX}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ldapdiff ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/ldapdiff.conf \
			${PREFIX}/etc/ldapdiff.conf.sample
		${MKDIR} ${DATADIR}/plugins
		${INSTALL_DATA} ${WRKSRC}/plugins/ldapskeleton.c ${DATADIR}/plugins

.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

post-install:
		${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
