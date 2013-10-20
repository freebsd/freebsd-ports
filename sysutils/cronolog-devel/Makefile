# $FreeBSD$

PORTNAME=	cronolog
PORTVERSION=	1.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://cronolog.org/patches/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Web log rotation utility that provides datestamp filenames

PLIST_FILES=	sbin/cronolog \
		sbin/cronosplit \
		man/man1/cronolog.1m.gz \
		man/man1/cronosplit.1m.gz

CONFLICTS=	cronolog-[0-9]*

WRKSRC=		${WRKDIR}/cronolog-${PORTVERSION}
INFO=		cronolog

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
