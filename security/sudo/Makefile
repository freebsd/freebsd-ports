# New ports collection makefile for:    sudo
# Version required:     1.5
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.4 1996/09/06 13:41:02 erich Exp $
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

.include <bsd.port.mk>
