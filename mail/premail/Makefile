# New ports collection makefile for: premail
# Version required:     0.45
# Premail homepage is http://www.c2.net/~raph/premail.html
#
# Date created:         31 Jan 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.7 1998/02/26 10:14:39 ache Exp $
#

DISTNAME=       premail-0.45
CATEGORIES=     security mail
MASTER_SITES=   ftp://utopia.hacktic.nl/pub/replay/pub/remailer/premail/

BUILD_DEPENDS+= pgp:${PORTSDIR}/security/pgp

MAINTAINER=	ache@FreeBSD.ORG

USE_PERL5=      Yes
NO_BUILD=       Yes
RESTRICTED=     "Author treats it as ITAR subject"

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} premail ${PREFIX}/bin
	install -d -m 555 ${PREFIX}/share/doc/premail
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   preferences doc-0.45.html doc-0.45.txt ${PREFIX}/share/doc/premail
	@echo
	@echo "Check ${PREFIX}/share/doc/premail for further instructions"
	@echo

.include <bsd.port.mk>
