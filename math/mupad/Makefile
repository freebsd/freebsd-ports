# New ports collection makefile for:	mupad
# Date created:		Apr 4 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mupad
PORTVERSION=	1.4.2
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.mupad.de/MuPAD/distrib/unix/%SUBDIR%/ \
		ftp://archives.cs.ehime-u.ac.jp/pub/MuPAD/distrib/unix/%SUBDIR%/
MASTER_SITE_SUBDIR=	. XVIEW
DISTFILES=	bin_linux_142.tgz share_142.tgz xview_linux.tgz
DIST_SUBDIR=	mupad

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

NO_CDROM=	"unsure to sell for profit"

USE_LINUX=		yes
ONLY_FOR_ARCHS=		i386

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes

MAN1=		mmg.1 mupad.1 xmupad.1
MANN=		xrastool.n xview.n

post-extract:
	@${RM} -f ${WRKSRC}/share/doc/man/man1/.#mmg.1.1.6

do-install:
	@${MKDIR} ${PREFIX}/mupad/freebsd/xview ${PREFIX}/mupad/share
	find ${WRKSRC} -name "*.orig" | xargs ${RM}
	${TAR} cf - -C ${WRKSRC}/xview . | ${TAR} xf - -C ${PREFIX}/mupad/freebsd/xview
	${TAR} cf - -C ${WRKSRC}/linux . | ${TAR} xf - -C ${PREFIX}/mupad/freebsd
	${TAR} --exclude man1 --exclude mann -cf - -C ${WRKSRC}/share . | ${TAR} xf - -C ${PREFIX}/mupad/share
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/mupad
.for d in COPYRIGHT INSTALL LICENSE LIC_EDU TroubleShooting
	${INSTALL_DATA} ${WRKSRC}/$d ${PREFIX}/mupad
.endfor
.for section in 1 n
.for d in ${MAN${section:U}}
	${INSTALL_MAN} ${WRKSRC}/share/doc/man/man${section}/$d ${PREFIX}/man/man${section}
.endfor
.endfor

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
