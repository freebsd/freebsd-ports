# New ports collection makefile for:	procmail
# Date created:		24 September 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	procmail
PORTVERSION=	3.15.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.procmail.org/pub/procmail/ \
		ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

MAINTAINER=	ache@FreeBSD.org

INSTALL_TARGET=	install-suid install.man

# It asks for list af directories to do test for file locking
# (defaults to /tmp and ".", so return should suffice in most cases).
.if !defined(PACKAGE_BUILDING) # handled in patch-aa
IS_INTERACTIVE=	yes
.endif
MAN1=		procmail.1 formail.1 lockfile.1
MAN5=		procmailex.5 procmailrc.5 procmailsc.5

.include <bsd.port.mk>
