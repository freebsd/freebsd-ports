# New ports collection makefile for:	mupad
# Date created:		Apr 4 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mupad
PORTVERSION=	2.5.0
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.mupad.de/MuPAD/distrib/unix/ \
		ftp://archives.cs.ehime-u.ac.jp/pub/MuPAD/distrib/unix/ \
		ftp://ftp.uni-paderborn.de/pub/MuPAD/distrib/unix/
DISTFILES=	bin_linux_scilab_250.tgz share_250.tgz
DIST_SUBDIR=	mupad

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

NO_CDROM=	"unsure to sell for profit"

USE_LINUX=		yes
ONLY_FOR_ARCHS=		i386

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes

MAN1=		killpvmd.1 mmg.1 mmgd.1 mupad.1 pvmdstatus.1 scilabstop.1 xmupad.1
MANN=		xrastool.n xview.n
do-install:
	@${MKDIR} ${PREFIX}/mupad/freebsd
	@${MKDIR} ${PREFIX}/mupad/share
	@${MKDIR} ${PREFIX}/mupad/packages
	find ${WRKSRC} -name "*.orig" | xargs ${RM}
	${RM} -rf ${WRKSRC}/packages/scilab/linux
	${RM} -rf ${WRKSRC}/packages/scilab/solaris
	${TAR} cf - -C ${WRKSRC}/linux . | ${TAR} xf - -C ${PREFIX}/mupad/freebsd
	${TAR} --exclude man1 --exclude mann -cf - -C ${WRKSRC}/share . | ${TAR} xf - -C ${PREFIX}/mupad/share
	${TAR} -cf - -C ${WRKSRC}/packages . | ${TAR} xf - -C ${PREFIX}/mupad/packages
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/mupad
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/mupad
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/mupad
.for d in mupad mmg mxdvi mxmupad mxvcam version20
	brandelf -t Linux ${PREFIX}/mupad/freebsd/bin/$d
.endfor

.for section in 1 n
.for d in ${MAN${section:U}}
	${INSTALL_MAN} ${WRKSRC}/share/doc/man/man${section}/$d ${PREFIX}/man/man${section}
.endfor
.endfor

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
