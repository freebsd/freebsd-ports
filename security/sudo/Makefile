# New ports collection makefile for:    sudo
# Version required:     1.5.8.2
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.18 1999/03/29 00:52:35 billf Exp $
#

DISTNAME=	cu-sudo.v1.5.9p1
PKGNAME=	sudo-1.5.9.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/sysadmin/sudo/

MAINTAINER=	mharo@FreeBSD.ORG

WRKSRC=		${WRKDIR}/sudo.v1.5.9p1
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-skey \
		--with-opie \
		--with-logfac=LOG_AUTH \
		--disable-log-wrap \
		--with-ignore-dot \
		--with-tty-tickets \
		--with-env-editor \
		--disable-root-sudo

MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

.include <bsd.port.mk>
