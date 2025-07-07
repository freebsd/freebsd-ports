PORTNAME=	vmtouch
PORTVERSION=	1.3.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Memory Toucher
WWW=		https://hoytech.com/vmtouch/

USE_GITHUB=	yes
GH_ACCOUNT=	hoytech
LICENSE=	BSD3CLAUSE

USES=		perl5 uidfix
USE_PERL5=	build # pod2man

PLIST_FILES=	bin/vmtouch \
		share/man/man8/vmtouch.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vmtouch ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/vmtouch.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
