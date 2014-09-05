# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	bbapm
PORTVERSION=	0.0.1
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE:C/%SUBDIR%/bbtools\/${PORTNAME}\/bbapm-0.0.1-freebsd-patch/}
PATCH_SITE_SUBDIR=	bbtools
PATCHFILES=	bbapm-0.0.1-freebsd-patch-2.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	APM monitor for the Blackbox slit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_XORG=	x11

do-install:
	${INSTALL} ${COPY} ${STRIP} ${WRKSRC}/bbapm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bbtools
.for a in README.bbapm bbapm.conf bbapm.nobb bbapm.style bbtoolsrc.in
	${INSTALL_DATA} ${WRKSRC}/data/${a} ${STAGEDIR}${PREFIX}/share/bbtools
.endfor

post-install:
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
