# New ports collection makefile for:	tftp-hpa
# Date created:				11 September 2008
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	tftp-hpa
PORTVERSION=	0.48
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kernel.org/pub/software/network/tftp/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Enhanced version of the BSD TFTP client and server

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_BZIP2=	yes
USE_GMAKE=	yes

MAN1=		tftp.1
MAN8=		in.tftpd.8 tftpd.8
NOMANCOMPRESS=	yes

PLIST_FILES=	bin/tftp sbin/in.tftpd

.include <bsd.port.mk>
