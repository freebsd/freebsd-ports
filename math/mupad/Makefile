# New ports collection makefile for:	mupad
# Date created:		Apr 4 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mupad
PORTVERSION=	3.1.1
CATEGORIES=	math linux
MASTER_SITES=	ftp://ftp.mupad.de/MuPAD/distrib/unix/
DISTNAME=	MuPADscilab-${PORTVERSION}-0.i386
EXTRACT_SUFX=   .rpm
DIST_SUBDIR=	mupad

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A sophisticated computer algebra system

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

NO_CDROM=	"unsure to sell for profit"

USE_LINUX=		yes
ONLY_FOR_ARCHS=		i386

NO_WRKSUBDIR=		yes

MAN1=		mmg.1 mmgd.1 mupad.1 xmupad.1
MANCOMPRESSED=	yes
EXTRACT_CMD=    rpm2cpio.pl
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=     | ${CPIO} -id --quiet
USE_REINPLACE=	yes
MUPADBASEDIR=MuPAD

do-build:
	@${MV} ${WRKSRC}/usr/local/MuPADscilab-${PORTVERSION}/linux ${WRKSRC}/usr/local/MuPADscilab-${PORTVERSION}/freebsd
.for d in manual mmg mupad mxdvi vcam xmupad xvc2jvx
	@${REINPLACE_CMD}  -e 's:%%PREFIX%%:${PREFIX}:g' \
		${WRKSRC}/usr/local/bin/${d}
.endfor
	${RM} -rf ${WRKSRC}/usr/local/MuPADscilab-${PORTVERSION}/share/doc/man

do-install:
	@${FIND} ${WRKSRC} -name "*.orig" | ${XARGS} ${RM}
	@${MKDIR} ${PREFIX}/${MUPADBASEDIR}
.for d in manual mmg mupad mxdvi vcam xmupad xvc2jvx
	@${INSTALL_SCRIPT} ${WRKSRC}/usr/local/bin/${d} ${PREFIX}/bin
.endfor
	@${TAR} cf - -C ${WRKSRC}/usr/local/MuPADscilab-${PORTVERSION} . | ${TAR} xf - -C ${PREFIX}/${MUPADBASEDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${MUPADBASEDIR}
.for d in mmg mupad mxdvi mxmupad xvc2jvx
	@${BRANDELF} -t Linux ${PREFIX}/${MUPADBASEDIR}/freebsd/bin/${d}
.endfor
.if !defined(NOPORTDOCS)
.for d in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/usr/share/man/man1/${d}.gz ${PREFIX}/man/man1
.endfor
	@${MKDIR} ${DOCSDIR}
	@${TAR} cf - -C ${WRKSRC}/usr/share/doc/MuPADscilab-${PORTVERSION} . | ${TAR} xf - -C ${DOCSDIR}
.endif

.include <bsd.port.mk>
