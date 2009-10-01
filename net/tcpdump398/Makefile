# New ports collection makefile for:	tcpdump398
# Date created:				1 October 2009
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	tcpdump398
PORTVERSION=	1.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.mavetju.org/download/adopted/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Ubiquitous network traffic analysis tool - FreeBSD 7 version for FreeBSD 8

PLIST_FILES=	bin/tcpdump398
MAN1=		tcpdump398.1

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		comes with the base OS, only applicable for 8.0 and higher
.endif

post-build:
	${GUNZIP_CMD} ${WRKSRC}/tcpdump.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${PREFIX}/bin/tcpdump398
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1 ${MAN1PREFIX}/man/man1/tcpdump398.1

.include <bsd.port.post.mk>
