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

MAINTAINER=	ports@FreeBSD.org
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdiff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/ldapdiff.conf \
		${PREFIX}/etc/ldapdiff.conf.sample
	@${MKDIR} ${DATADIR}/samples
.for i in ${SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${i} ${DATADIR}/samples
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in CHANGES README TODO ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
