PORTNAME=	cronolog
PORTVERSION=	1.7.1
PORTREVISION=	2
DISTVERSIONSUFFIX=	-beta
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/cronolog-devel/
PKGNAMESUFFIX=	-devel

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Web log rotation utility that provides datestamp filenames
WWW=		https://BSDforge.com/projects/sysutils/cronolog-devel

LICENSE=	APACHE10

USES=		shebangfix tar:xz

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFLICTS=	cronolog

SHEBANG_FILES=	src/cronosplit
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INFO=		cronolog
PLIST_FILES=	sbin/cronolog \
		sbin/cronosplit \
		share/man/man1/cronolog.1m.gz \
		share/man/man1/cronosplit.1m.gz

.include <bsd.port.mk>
