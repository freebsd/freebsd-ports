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

USES=		uidfix
MAKE_ENV=	BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX}

PLIST_FILES=	bin/scr2txt \
		man/man1/scr2txt.1.gz

.include <bsd.port.mk>
