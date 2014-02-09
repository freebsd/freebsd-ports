# Created by: nik
# $FreeBSD$

PORTNAME=	scr2txt
PORTVERSION=	1.2
CATEGORIES=	textproc

MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= nik
NO_WRKSUBDIR=	yes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts the output of "vidcontrol -p" to text

PLIST_FILES=	bin/scr2txt \
		man/man1/scr2txt.1.gz

do-install:
	@cd ${WRKSRC}; ${MAKE} BINDIR=${STAGEDIR}${PREFIX}/bin SHAREDIR=${STAGEDIR}${PREFIX} install

.include <bsd.port.mk>
