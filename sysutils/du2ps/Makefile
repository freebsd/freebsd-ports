# New ports collection makefile for:	du2ps
# Date created:		31 May 2001
# Whom:			Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	du2ps
PORTVERSION=	3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://line.to/mac/soft/du2ps/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	Filter for converting output of du to PostScript file

# Nkf is required for just converting character code of japanese manual
BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

ALL_TARGET=
MAKE_ARGS=	CFLAGS="${CFLAGS}"

MAN1=		du2ps.1
MANLANG=	"" ja
PLIST_FILES=	bin/du2ps
.if !defined(NOPORTDOCS)
PORTDOCS=	README.ver1 README.ver2 README.xdu du2ps.pdf du2psj.pdf
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/du2ps ${PREFIX}/bin/du2ps
	${INSTALL_MAN} ${WRKSRC}/du2ps.1 ${PREFIX}/man/man1/du2ps.1
	nkf -e ${WRKSRC}/du2ps.1j > ${WRKSRC}/du2ps.1.ja
	${INSTALL_MAN} ${WRKSRC}/du2ps.1.ja ${PREFIX}/man/ja/man1/du2ps.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
