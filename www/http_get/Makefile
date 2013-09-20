# Created by: Aaron Zauner <az_mail@gmx.at>
# $FreeBSD$

PORTNAME=	http_get
PORTVERSION=	1.0.20100619
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/http_get/
DISTNAME=	${PORTNAME}_19jun2010

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Dump http-contents to stdout

WRKSRC=		${WRKDIR}/http_get
MAKEFILE=	${FILESDIR}/Makefile.bsd

MAN1=		http_get.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/http_get

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
