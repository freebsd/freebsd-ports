# New ports collection makefile for:    acron
# Version required:     1.2.4
# Date created:         13 Dec 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1997/12/15 08:44:23 tg Exp $
#

DISTNAME=       acron
PKGNAME=	acron-1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/others/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

NO_BUILD=	yes

post-patch:
	@/usr/bin/perl -pi -e "s|@@PREFIX@@|${PREFIX}|g;" ${WRKSRC}/whats

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/whats ${PREFIX}/bin
	ln -sf ${PREFIX}/bin/whats ${PREFIX}/bin/acron
	${INSTALL_DATA} ${WRKSRC}/acron ${PREFIX}/share/misc

.include <bsd.port.mk>
