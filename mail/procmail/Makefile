# New ports collection makefile for:	procmail
# Version required:     3.11pre3
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.18 1995/06/26 04:34:40 asami Exp $
#

DISTNAME=       procmail-3.11pre3
PKGNAME=        procmail-3.11.3
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/
INSTALL_TARGET= install-suid install.man

MAINTAINER=     ache@FreeBSD.ORG

# It asks for list af directories to do test for file locking
# (defaults to /tmp and ".", so return should suffice in most cases).
IS_INTERACTIVE=	yes

.include <bsd.port.mk>
