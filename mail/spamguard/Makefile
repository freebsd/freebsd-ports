# New ports collection makefile for:   spamguard
# Date created:                 21 Oct 2003
# Whom:                         Omer Faruk Sen <ofsen@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	spamguard
PORTVERSION=	1.6
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/spamguard/

MAINTAINER=	ofsen@enderunix.org
COMMENT=	MTA spam prevention program for qmail/postfix/sendmail

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		AUTHORS CHANGELOG COPYING INSTALL \
		POST-INSTALL README THANKS 
DOCS_TR=	BENIOKU COPYING DEGISIKLIKLER KURULUM \
		KURULUM-SONRASI YAPILACAKLAR YAZARLAR

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spamguard ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/tr
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${WRKSRC}/tr && ${INSTALL_DATA} ${DOCS_TR} ${DOCSDIR}/tr
.endif
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' pkg-message > ${PKGMESSAGE}

.include <bsd.port.mk>
