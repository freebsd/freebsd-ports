# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vobcopy
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://vobcopy.org/download/ \
		LOCAL/ehaupt

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Decrypts and copies DVD .vob files

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	--with-lfs --with-dvdread-libs=${LOCALBASE}

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/vobcopy man/man1/vobcopy.1.gz
PORTDOCS=	COPYING Changelog README TODO \
		alternative_programs.txt
OPTIONS_DEFINE=	DOCS

post-extract:
	@${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${REINPLACE_CMD} -E -e 's|(fopen\( *"/etc/)mtab|\1fstab|; \
		s|iso9660|cd9660|' ${WRKSRC}/dvd.c
	@${REINPLACE_CMD} -E -e 's|declare -i i=0||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# -CURRENT after 500041 has getopt_long
# do not use libgnugetopt
	@${REINPLACE_CMD} -E \
		-e 's|-lgnugetopt||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# fix typo
	@${REINPLACE_CMD} -E \
		-e 's|FreeBSD_Version|FreeBSD_version|' \
		${WRKSRC}/dvd.c
# no such flag under FreeBSD
# fdatasync(2) -> fsync(2)
	@${REINPLACE_CMD} -E \
		-e 's|O_LARGEFILE|0|' \
		-e 's|fdatasync|fsync|g' \
		${WRKSRC}/vobcopy.c

post-configure:
	@${REINPLACE_CMD} -E -e 's|^CC.+||; s|^PREFIX.+||; \
		s|/usr/local/|${LOCALBASE}/|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${STAGEDIR}${PREFIX}/bin/vobcopy
	${INSTALL_MAN} ${WRKSRC}/vobcopy.1${MAN1_SUFX} \
		${STAGEDIR}${MANPREFIX}/man/man1/vobcopy.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
