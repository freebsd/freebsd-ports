# New ports collection makefile for:    ldapdiff
# Date created:         15 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org)
#
# $FreeBSD$
#

PORTNAME=       ldapdiff
PORTVERSION=    0.8.3
CATEGORIES=     net
MASTER_SITES=   http://webtomware.rhoen.de/ \
		http://unixpages.org/distfiles/

MAINTAINER=     chris@unixpages.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-ldap-dir=${PREFIX} \
		--with-iconv-dir=${PREFIX}

.if defined(WITH_OPENLDAP1)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap
.else
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2
.endif

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
