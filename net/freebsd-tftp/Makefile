# Ports collection makefile for:	net/freebsd-tftp
# Whom:					Edwin Groothuis <edwin@FreeBSD.org>
# Date created:				2008-01-30
#
# $FreeBSD$
#

PORTNAME=	freebsd-tftp
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@FreeBSD.org
COMMENT=	Upcoming replacement for tftp(1) and tftpd(8)

PLIST_FILES=	bin/tftp libexec/tftpd

WRKSRC=		${WRKDIR}
NOPACKAGE=	Installs software in /usr/libexec and /usr/bin
PREFIX=		/usr

MAN8=		tftpd.8
MAN1=		tftp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr.bin/tftp/tftp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/libexec/tftpd/tftpd ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/usr.bin/tftp/tftp.1 ${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/libexec/tftpd/tftpd.8 ${PREFIX}/share/man/man8

.include <bsd.port.mk>
