# New ports collection makefile for:    ldapdiff
# Date created:         15 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org)
#
# $FreeBSD$
#

PORTNAME=	ldapdiff
PORTVERSION=	0.9.0
CATEGORIES=	net
MASTER_SITES=	http://webtomware.rhoen.de/ \
		http://unixpages.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for patching LDAP directories using LDIF files

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
.if defined(WITH_OPENLDAP1)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap12
.else
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/${LDAP_PORT}
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-ldap-dir=${PREFIX} \
		--with-iconv-dir=${PREFIX}
LDAP_PORT?=	net/openldap20-client

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdiff ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ldapdiff.conf \
		${PREFIX}/etc/ldapdiff.conf.sample
	@${MKDIR} ${DATADIR}/samples
.for i in addentry webtomware.init.ldif webtomware.user.ldif
	${INSTALL_DATA} ${WRKSRC}/samples/${i} ${DATADIR}/samples
.endfor
	@${MKDIR} ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/ldapskeleton.c ${DATADIR}/plugins
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in CHANGES README TODO ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
