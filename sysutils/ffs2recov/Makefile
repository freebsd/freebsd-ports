# Created by: sten@blinkenlights.nl

PORTNAME=	ffs2recov
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/ffs2recov/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Utility to recover UFS2 filesystems

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_13=	Changes made to the ffs2 filesystem in FreeBSD 13 are no longer compatible with ffs2recov
BROKEN_FreeBSD_14=	Changes made to the ffs2 filesystem in FreeBSD 13 are no longer compatible with ffs2recov

USES=		compiler:c11 tar:bzip2 uidfix
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/ffs2recov \
		man/man8/ffs2recov.8.gz

MAKE_ENV=	BINDIR=${PREFIX}/sbin MANDIR=${MANPREFIX}/man/man \
		WARNS=0

.include <bsd.port.mk>
