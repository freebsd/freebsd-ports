# New ports collection makefile for:    sudo
# Version required:     1.5.3
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.8 1997/10/22 08:46:03 obrien Exp $
#

DISTNAME=	cu-sudo.v1.5.3
PKGNAME=	sudo-1.5.3
CATEGORIES=	security
MASTER_SITES=	ftp://freestuff.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erich@rrnet.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-C2 --with-skey --with-fbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5.3
MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

.include <bsd.port.mk>
