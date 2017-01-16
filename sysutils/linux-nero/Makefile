# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nero
PORTVERSION=	4.0.0.0
PORTREVISION=	3
CATEGORIES=	sysutils emulators
MASTER_SITES=	http://ftp20.us.nero.com/software/NeroLINUX/
DISTFILES=	${PORTNAME}linux-${PORTVERSION}-x86.rpm

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	CD/DVD disk burner

RESTRICTED=	Must be downloaded from their website and a serial number must be bought
DEPRECATED=	Probably cannot actually burn CD/DVD on recent FreeBSD
EXPIRATION_DATE=2017-03-01

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		linux
USE_LDCONFIG=	yes
USE_LINUX=	gtk2
USE_LINUX_PREFIX=	yes

do-install:
	(cd ${WRKSRC} && ${FIND} * | ${CPIO} -dumpl ${STAGEDIR}${PREFIX})

.include <bsd.port.mk>
