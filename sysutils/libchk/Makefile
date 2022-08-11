PORTNAME=	libchk
PORTVERSION=	1.10.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ \
		LOCAL/knu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to check shared library links

LICENSE=	BSD2CLAUSE

USES=			tar:bzip2 uidfix
USE_RUBY=		yes

MAKE_ARGS=	PREFIX="${PREFIX}"

PLIST_FILES=	man/man1/libchk.1.gz \
		sbin/libchk

.include <bsd.port.mk>
