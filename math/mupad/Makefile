# New ports collection makefile for:	mupad
# Date created:		Apr 4 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mupad
PORTVERSION=	2.5.3
PORTREVISION=	2
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.mupad.de/MuPAD/distrib/unix/
DISTNAME=	mupad_linux_scilab_253
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	mupad

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A sophisticated computer algebra system

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
	@${MKDIR} ${PREFIX}/mupad/packages
	@${FIND} ${WRKSRC} -name "*.orig" | ${XARGS} ${RM}
	@${RM} -rf ${WRKSRC}/packages/scilab/linux
	@${RM} -rf ${WRKSRC}/linux/lib/libXpm.so*
	@${RM} -rf ${WRKSRC}/packages/scilab/linux
	@${RM} -rf ${WRKSRC}/packages/scilab/solaris
	@${TAR} cf - -C ${WRKSRC}/linux . | ${TAR} xf - -C ${PREFIX}/mupad/freebsd
	@${TAR} --exclude doc --exclude man1 --exclude mann -cf - -C ${WRKSRC}/share . | ${TAR} xf - -C ${PREFIX}/mupad/share
	@${TAR} -cf - -C ${WRKSRC}/packages --exclude CVS . | ${TAR} xf - -C ${PREFIX}/mupad/packages
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/mupad
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/mupad
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/mupad
.for d in mmg mupad mxdvi mxmupad mxvcam
	@${BRANDELF} -t Linux ${PREFIX}/mupad/freebsd/bin/$d
.endfor

.for d in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/share/doc/man/man1/$d ${PREFIX}/man/man1
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/mupad/share/doc
	@${TAR} cf - -C ${WRKSRC}/share/doc --exclude man1 --exclude mann . | ${TAR} xf - -C ${PREFIX}/mupad/share/doc
.endif

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
