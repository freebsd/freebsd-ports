# New ports collection makefile for:	vodmr
# Date created:				12 January 2003.
# Whom:					James Raftery <james@now.ie>
#
# $FreeBSD$
#
# Use  make -DWITHOUT_TCPSERVER ...  to install without a dependenacy
# on djb's tcpserver.
#

PORTNAME=	vodmr
PORTVERSION=	0.12
CATEGORIES=	mail perl5
MASTER_SITES=	http://romana.now.ie/software/ \
		http://www.lecter.phlegethon.org/vodmr/

MAINTAINER=	james@now.ie
COMMENT=	An ODMR/ATRN server for vpopmail+qmail

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/CDB_File.pm:${PORTSDIR}/databases/p5-CDB_File \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/vpopmail.pm:${PORTSDIR}/mail/p5-vpopmail \
		${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC

.if !defined(WITHOUT_TCPSERVER)
RUN_DEPENDS+=	tcpserver:${PORTSDIR}/sysutils/ucspi-tcp
.endif

NO_BUILD=	YES
USE_PERL5_RUN=	YES
USE_REINPLACE=	YES

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${SED} -e 's|DOCSDIR|${PREFIX}/share/doc/vodmr|' \
		-e 's|SCRIPT|${PREFIX}/sbin/odmrd|' ${MASTERDIR}/pkg-message \
		> ${WRKDIR}/pkg-message

do-configure:
	${REINPLACE_CMD} -e 's|^\#!/usr/bin/perl|\#!${PERL}|' ${WRKSRC}/odmrd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/odmrd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/odmrd.sh-sample ${PREFIX}/etc/rc.d

.if !defined(NOPORTDOCS)
PORTDOCS=	FAQ README INSTALL INTERNALS TODO sample-odmrd.rules

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
