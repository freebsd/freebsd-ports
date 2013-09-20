# Created by: chuck@pkix.net
# $FreeBSD$

PORTNAME=	dvd+rw-tools
PORTVERSION=	7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pkix.net/mirror/fy.chalmers.se/ \
		http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVD burning software

BUILD_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools
# On some systems, among them one 900044 i386, the do-build-invoked
# "make" will just do nothing for reasons not yet found, as of
# dvd+rw-tools 7.1. It is supposed to call
# (m4 -DOS=`uname -s` Makefile.m4 | make -f - dvd+rw-tools)
# but returns success right away.
# Using gmake bypasses this problem for unknown reasons. Please leave it in,
# until the problem is analyzed and fixed - and please comment the fix here.
USE_GMAKE=	yes

MAN1=		growisofs.1
BIN_FILES=	growisofs dvd+rw-format dvd+rw-booktype dvd+rw-mediainfo dvd-ram-control
PLIST_FILES=	${BIN_FILES:S|^|bin/|}
PORTDOCS=	index.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//' ${WRKSRC}/Makefile.m4

do-install:
.for i in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${MANPREFIX}/man/man1/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
