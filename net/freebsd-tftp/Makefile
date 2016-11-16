# Created by: Edwin Groothuis <edwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freebsd-tftp
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Upcoming replacement for tftp(1) and tftpd(8)

PLIST_FILES=	bin/tftp libexec/tftpd \
		share/man/man8/tftpd.8.gz share/man/man1/tftp.1.gz

WRKSRC=		${WRKDIR}
NO_PACKAGE=	Installs software in /usr/libexec and /usr/bin
PREFIX=		/usr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr.bin/tftp/tftp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/libexec/tftpd/tftpd ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/usr.bin/tftp/tftp.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/libexec/tftpd/tftpd.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
