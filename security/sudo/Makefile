# New ports collection makefile for:    sudo
# Version required:     1.5
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.5 1996/11/12 00:05:35 obrien Exp $
#

DISTNAME=	cu-sudo.v1.5
PKGNAME=	sudo-1.5
CATEGORIES=	security
MASTER_SITES=	ftp://freestuff.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erich@rrnet.com

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-C2 --with-fbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5
MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

.include <bsd.port.mk>
