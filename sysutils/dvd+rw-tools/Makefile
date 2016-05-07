# Created by: Charles Swiger <chuck@pkix.net>
# $FreeBSD$

PORTNAME=	dvd+rw-tools
PORTVERSION=	7.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkix.net/mirror/fy.chalmers.se/ \
		http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD burning software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cdrecord:sysutils/cdrtools
RUN_DEPENDS=	cdrecord:sysutils/cdrtools

# On some systems, among them one 900044 i386, the do-build-invoked
# "make" will just do nothing for reasons not yet found, as of
# dvd+rw-tools 7.1. It is supposed to call
# (m4 -DOS=`uname -s` Makefile.m4 | make -f - dvd+rw-tools)
# but returns success right away.
# Using gmake bypasses this problem for unknown reasons. Please leave it in,
# until the problem is analyzed and fixed - and please comment the fix here.
USES=		gmake

BIN_FILES=	dvd+rw-booktype dvd+rw-format dvd+rw-mediainfo \
		dvd-ram-control growisofs
PLIST_FILES=	${BIN_FILES:S|^|bin/|} \
		man/man1/growisofs.1.gz
PORTDOCS=	index.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//' ${WRKSRC}/Makefile.m4

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
