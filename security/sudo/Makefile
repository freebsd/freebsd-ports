# New ports collection makefile for:    sudo
# Version required:     1.5.6.5
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.14 1998/10/27 04:54:42 asami Exp $
#

DISTNAME=	cu-sudo.v1.5.7p4
PKGNAME=	sudo-1.5.7.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erich@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-C2 --with-skey --with-fbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5.7p4
MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

.include <bsd.port.mk>
