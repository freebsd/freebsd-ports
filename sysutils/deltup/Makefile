# New ports collection makefile for:	deltup
# Date created:		2005-05-18
# Whom:			Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deltup
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://deltup.org/e107_files/downloads/ \
		LOCAL/rafan \
		http://www.bzip.org/${BZIP2_102}/:bzip2102src \
		http://www.bzip.org/${BZIP2_103}/:bzip2103src
DISTFILES+=	${PORTNAME}-${PORTVERSION}.tar.gz ${BZIP2_102_SOURCE}:bzip2102src ${BZIP2_103_SOURCE}:bzip2103src

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Source delta update program

RUN_DEPENDS=	bdelta:${PORTSDIR}/misc/bdelta \
		xdelta:${PORTSDIR}/misc/xdelta \
		gzip>=1:${PORTSDIR}/archivers/gzip

BZIP2_102_SOURCE=	bzip2-${BZIP2_102}.tar.gz
BZIP2_103_SOURCE=	bzip2-${BZIP2_103}.tar.gz

BZIP2_102=	1.0.2
BZIP2_103=	1.0.3

USE_OPENSSL=	yes
USE_GMAKE=	yes
ALL_TARGET=	deltup
PLIST_FILES=	bin/deltup \
		bin/bzip2_1.0.2 \
		bin/bzip2_1.0.3
MAN1=		deltup.1
WRKSRC_BZIP2_102=	${WRKDIR}/bzip2-${BZIP2_102}
WRKSRC_BZIP2_103=	${WRKDIR}/bzip2-${BZIP2_103}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deltup ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC_BZIP2_102}/bzip2 ${PREFIX}/bin/bzip2_1.0.2
	${INSTALL_PROGRAM} ${WRKSRC_BZIP2_103}/bzip2 ${PREFIX}/bin/bzip2_1.0.3
	${INSTALL_MAN} ${WRKSRC}/deltup.1 ${PREFIX}/man/man1
pre-build:
	@${REINPLACE_CMD} -e 's|-Wall -Winline -O2|-Wall -Winline -O2 ${CFLAGS}|' \
	${WRKSRC_BZIP2_102}/Makefile
	@${REINPLACE_CMD} -e 's|-Wall -Winline -O -g|-Wall -Winline -O2 ${CFLAGS}|' \
	${WRKSRC_BZIP2_103}/Makefile
	@cd ${WRKSRC_BZIP2_102}; ${GMAKE} bzip2; \
	cd ${WRKSRC_BZIP2_103}; ${GMAKE} bzip2;
.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
