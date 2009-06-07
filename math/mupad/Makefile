# New ports collection makefile for:	mupad
# Date created:		Apr 4 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mupad
PORTVERSION=	3.2.0
CATEGORIES=	math linux
MASTER_SITES=	#
DISTNAME=	mupad-${PORTVERSION}-3-linux-i386
EXTRACT_SUFX=   .rpm
DIST_SUBDIR=	mupad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sophisticated computer algebra system

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
USE_LINUX_APPS+=dri

NO_CDROM=	unsure to sell for profit

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${file})
IGNORE= you can go http://www.mupad.de/download/mupadpro3.php and download `Linux, 32bit, i386 German. RPM package'
.endif
.endfor

USE_LINUX=		yes
ONLY_FOR_ARCHS=		i386

NO_WRKSUBDIR=		yes

EXTRACT_CMD=    rpm2cpio.pl
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=     | ${CPIO} -id --quiet
MUPADBASEDIR=MuPAD-${PORTVERSION}

do-build:
	@${MV} ${WRKSRC}/opt/MuPAD-${PORTVERSION}/linux ${WRKSRC}/opt/MuPAD-${PORTVERSION}/freebsd
.for d in mmg32 mupad32 xmupad32 xvc2jvx32
	@${REINPLACE_CMD}  -e 's:/opt/MuPAD-${PORTVERSION}/share/bin:${PREFIX}/${MUPADBASEDIR}/share/bin:g' \
		${WRKSRC}/usr/local/bin/${d}
.endfor

do-install:
	@${FIND} ${WRKSRC} -name "*.orig" | ${XARGS} ${RM}
	@${MKDIR} ${PREFIX}/${MUPADBASEDIR}
	@${TAR} cf - -C ${WRKSRC}/opt/MuPAD-${PORTVERSION} . | ${TAR} xf - -C ${PREFIX}/${MUPADBASEDIR}
.for d in mmg mupad xmupad xvc2jvx
	@${INSTALL_SCRIPT} ${WRKSRC}/usr/local/bin/${d}32 ${PREFIX}/bin
	@${LN} -s ${PREFIX}/bin/${d}32 ${PREFIX}/bin/${d}
.endfor

.include <bsd.port.mk>
