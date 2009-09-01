# New ports collection makefile for:    ldapdiff
# Date created:         15 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org)
#
# $FreeBSD$
#

PORTNAME=	ldapdiff
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.ale.org/pub/mirrors/openpkg/sources/DST/ldapdiff/ \
		http://webtomware.rhoen.de/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	A utility for patching LDAP directories using LDIF files

USE_ICONV=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE} \
		--with-ldap-dir=${LOCALBASE} \
		--with-iconv-dir=${LOCALBASE}
SAMPLES=	addentry webtomware_without_jpeg.user.ldif \
		webtomware.init.ldif webtomware.user.ldif
MAN1=		ldapdiff.1

PORTDOCS=	CHANGES ChangeLog README TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdiff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/ldapdiff.conf \
		${PREFIX}/etc/ldapdiff.conf.sample
	@${MKDIR} ${DATADIR}/samples
.for sample in ${SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${sample} ${DATADIR}/samples
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
