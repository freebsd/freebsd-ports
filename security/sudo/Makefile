# New ports collection makefile for:    sudo
# Version required:     1.5.3
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp $
#

DISTNAME=	cu-sudo.v1.5.4
PKGNAME=	sudo-1.5.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erich@rrnet.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-C2 --with-skey --with-fbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5.4
MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

.include <bsd.port.mk>
