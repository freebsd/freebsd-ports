# New ports collection makefile for:	bbapm
# Date created:				3 August 2001
# Whom:				Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	bbapm
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bbtools

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	bbtools
PATCHFILES=	bbapm-0.0.1-freebsd-patch-2.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	APM monitor for the Blackbox slit

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bbapm share/bbtools/README.bbapm share/bbtools/bbapm.conf \
		share/bbtools/bbapm.nobb share/bbtools/bbapm.style \
		share/bbtools/bbtoolsrc.in

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g operator \
		-m 2555 ${WRKSRC}/bbapm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/bbtools
.for a in README.bbapm bbapm.conf bbapm.nobb bbapm.style bbtoolsrc.in
	${INSTALL_DATA} ${WRKSRC}/data/${a} ${PREFIX}/share/bbtools
.endfor

post-install:
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
