# $FreeBSD$

PORTNAME=	cronolog
PORTVERSION=	1.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://BSDforge.com/projects/source/sysutils/cronolog-devel/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Web log rotation utility that provides datestamp filenames

LICENSE=	APACHE10

USES=		shebangfix tar:xz

SHEBANG_FILES=	src/cronosplit

PLIST_FILES=	sbin/cronolog \
		sbin/cronosplit \
		man/man1/cronolog.1m.gz \
		man/man1/cronosplit.1m.gz

CONFLICTS=	cronolog-[0-9]*

WRKSRC=		${WRKDIR}/cronolog-${PORTVERSION}
INFO=		cronolog

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
