# Created by: corky1951@comcast.net
# $FreeBSD$

PORTNAME=	ranpwd
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
#MASTER_SITES=	KERNEL_ORG
MASTER_SITES=	http://artfiles.org/kernel.org/pub/%SUBDIR%/ \
		http://debian.securedservers.com/kernel/pub/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/pub/%SUBDIR%/ \
		http://ftp.naist.jp/pub/Linux/kernel.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	software/utils/admin/ranpwd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate random passwords

LICENSE=	GPLv2 # (or later)

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ranpwd man/man1/ranpwd.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ranpwd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ranpwd.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
