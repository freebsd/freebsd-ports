# New ports collection makefile for:	VOB dvd rip
# Date created:				Sun May 12 09:25:37 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vobcopy
PORTVERSION=	0.5.14
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Decrypts and copies DVD .vob files

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

USE_BZIP2=	yes
USE_GETOPT_LONG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
USE_REINPLACE=	yes

ALL_TARGET=	${PORTNAME}

MAN1=	vobcopy.1

PLIST_FILES=	bin/vobcopy
PORTDOCS=	COPYING Changelog README Release-Notes TODO \
		alternative_programs.txt

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E -e 's|(fopen\("/etc/)mtab|\1fstab|; \
		s|iso9660|cd9660|' ${WRKSRC}/dvd.c
	@${REINPLACE_CMD} -E -e 's|declare -i i=0||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# -CURRENT after 500041 has getopt_long
# do not use libgnugetopt
.if ${OSVERSION} >= 500041
	@${REINPLACE_CMD} -E \
		-e 's|-lgnugetopt||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|#include <stdint.h>||' \
		${WRKSRC}/vobcopy.c
.endif
# fix typo
	@${REINPLACE_CMD} -E \
		-e 's|FreeBSD_Version|FreeBSD_version|' \
		${WRKSRC}/dvd.c

post-configure:
	@${REINPLACE_CMD} -E -e 's|^CC.+||; s|^PREFIX.+||; \
		s|/usr/local/|${LOCALBASE}/|' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${PREFIX}/bin/vobcopy
	@${INSTALL_MAN} ${WRKSRC}/vobcopy.1${MAN1_SUFX} \
		${MANPREFIX}/man/man1/vobcopy.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
