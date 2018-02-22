# Created by: Alex Deiter <tiamat@komi.mts.ru>
# $FreeBSD$

PORTNAME=	imapsync
PORTVERSION=	1.836
DISTVERSIONPREFIX=	imapsync-
CATEGORIES=	mail perl5

MAINTAINER=	pi@FreeBSD.org
COMMENT=	IMAP synchronization, copy or migration tool

LICENSE=	NO_LIMIT_PUBLIC_LICENSE
LICENSE_NAME=	NO LIMIT PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-Mail-IMAPClient>0:mail/p5-Mail-IMAPClient \
		p5-Term-ReadKey>0:devel/p5-Term-ReadKey \
		p5-IO-Tee>0:devel/p5-IO-Tee \
		p5-Readonly>0:devel/p5-Readonly \
		p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL \
		p5-Unicode-String>0:converters/p5-Unicode-String \
		p5-File-Copy-Recursive>0:devel/p5-File-Copy-Recursive \
		p5-Sys-MemInfo>0:devel/p5-Sys-MemInfo \
		p5-IO-Socket-INET6>0:net/p5-IO-Socket-INET6

USES=		cpe perl5 tar:tgz shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_GITHUB=	yes

CPE_VENDOR=	gilles_lamiral
NO_BUILD=	yes
NO_ARCH=	yes

PORTSCOUT=	limit:^1\.(\d\.){3}

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

POD2MAN?=	pod2man

do-install:
	${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
