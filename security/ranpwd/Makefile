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

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		ranpwd.1
PLIST_FILES=	bin/ranpwd

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ranpwd ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ranpwd.1 ${MANPREFIX}/man/man1)

.include <bsd.port.mk>
