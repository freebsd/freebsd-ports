# New ports collection makefile for:    ldapdiff
# Date created:         15 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org)
#
# $FreeBSD$
#

PORTNAME=	ldapdiff
PORTVERSION=	1.0.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.ale.org/pub/mirrors/openpkg/sources/DST/ldapdiff/ \
		http://webtomware.rhoen.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for patching LDAP directories using LDIF files

USE_ICONV=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-ldap-dir=${PREFIX} \
		--with-iconv-dir=${PREFIX}

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
