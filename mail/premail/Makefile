# New ports collection makefile for: premail
# Version required:     0.46
# Premail homepage is http://www.c2.net/~raph/premail.html
#
# Date created:         31 Jan 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.11 1998/10/07 10:14:36 ache Exp $
#

DISTNAME=       premail-0.46
CATEGORIES=     security mail
MASTER_SITES=   ftp://ftp.jpunix.com/pub/remailer-tools/ \
		ftp://ftp.kiarchive.ru/unix/crypto/
WRKSRC=         ${WRKDIR}/premail

BUILD_DEPENDS+= pgp:${PORTSDIR}/security/pgp

MAINTAINER=	ache@FreeBSD.ORG

USE_PERL5=      Yes
NO_BUILD=       Yes
RESTRICTED=     "Author treats it as ITAR subject"

post-patch:
	cd ${WRKSRC}; \
	cp premail premail.old; \
	sed 's=#!/usr/local/bin/perl=#!${PERL} -w=' < premail.old > premail

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} premail ${PREFIX}/bin
	install -d -m 555 ${PREFIX}/share/doc/premail
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   preferences doc-0.46.html doc-0.46.txt ${PREFIX}/share/doc/premail
	@echo
	@echo "Check ${PREFIX}/share/doc/premail for further instructions"
	@echo

.include <bsd.port.mk>
