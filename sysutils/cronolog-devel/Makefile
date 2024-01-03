PORTNAME=	cronolog
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/cronolog-devel/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Web log rotation utility that provides datestamp filenames
WWW=		https://BSDforge.com/projects/sysutils/cronolog-devel

LICENSE=	APACHE10

BROKEN=		Unfetchable

USES=		shebangfix tar:xz

SHEBANG_FILES=	src/cronosplit

PLIST_FILES=	sbin/cronolog \
		sbin/cronosplit \
		man/man1/cronolog.1m.gz \
		man/man1/cronosplit.1m.gz

CONFLICTS=	cronolog

WRKSRC=		${WRKDIR}/cronolog-${PORTVERSION}
INFO=		cronolog

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
