# New ports collection makefile for:	mupad
# Date created:		Apr 4 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mupad
PORTVERSION=	2.0.0
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.mupad.de/MuPAD/distrib/unix/ \
		ftp://archives.cs.ehime-u.ac.jp/pub/MuPAD/distrib/unix/ \
		ftp://ftp.uni-paderborn.de/pub/MuPAD/distrib/unix/
DISTFILES=	bin_linux_200.tgz share_200.tgz
DIST_SUBDIR=	mupad

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

NO_CDROM=	"unsure to sell for profit"

USE_LINUX=		yes
ONLY_FOR_ARCHS=		i386

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes

MAN1=		mmg.1 mmgd.1 mupad.1 xmupad.1

do-install:
	@${MKDIR} ${PREFIX}/mupad/freebsd
	@${MKDIR} ${PREFIX}/mupad/share
	find ${WRKSRC} -name "*.orig" | xargs ${RM}
	${TAR} cf - -C ${WRKSRC}/linux . | ${TAR} xf - -C ${PREFIX}/mupad/freebsd
	${TAR} --exclude man1 -cf - -C ${WRKSRC}/share . | ${TAR} xf - -C ${PREFIX}/mupad/share
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/mupad
	${LN} -s ${PREFIX}/mupad/share/unix/locale/C/License.help ${PREFIX}/mupad/LICENSE
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/mupad
.for d in mupad mmg
	brandelf -t Linux ${PREFIX}/mupad/freebsd/bin/$d
.endfor
.for section in 1
.for d in ${MAN${section:U}}
	${INSTALL_MAN} ${WRKSRC}/share/doc/man/man${section}/$d ${PREFIX}/man/man${section}
.endfor
.endfor

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
