# New ports collection makefile for:	du2ps
# Date created:		31 May 2001
# Whom:			Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	du2ps
PORTVERSION=	2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.shobi-u.ac.jp/~tnagae/src/ps-c/du2ps/du2ps-2.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	Filter for converting output of du to PostScript file

# Nkf is required for just converting character code of japanese manual
BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

MAKEFILE=	makefile
ALL_TARGET=

MAN1=		du2ps.1
MANLANG=	"" ja
PLIST_FILES=	bin/du2ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/du2ps ${PREFIX}/bin/du2ps
	${INSTALL_MAN} ${FILESDIR}/du2ps.1 ${PREFIX}/man/man1/du2ps.1
	nkf -e ${WRKSRC}/du2ps.man > ${WRKDIR}/du2ps.1.ja
	${INSTALL_MAN} ${WRKDIR}/du2ps.1.ja ${PREFIX}/man/ja/man1/du2ps.1

.include <bsd.port.mk>
