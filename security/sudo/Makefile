# New ports collection makefile for:    sudo
# Version required:     1.5.3
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.6 1996/11/18 14:13:33 asami Exp $
#

DISTNAME=	cu-sudo.v1.5.3
PKGNAME=	sudo-1.5.3
CATEGORIES=	security
MASTER_SITES=	ftp://freestuff.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erich@rrnet.com

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-C2 --with-fbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5.3
MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

.include <bsd.port.mk>
