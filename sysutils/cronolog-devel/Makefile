PORTNAME=	cronolog
DISTVERSION=	1.7.2
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	-devel

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Web log rotation utility that provides datestamp filenames
WWW=		https://BSDforge.com/projects/sysutils/cronolog-devel

LICENSE=	APACHE10

USES=		shebangfix

SHEBANG_FILES=	src/cronosplit

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFLICTS=	cronolog

SHEBANG_FILES=	src/cronosplit
WRKSRC=		${WRKDIR}/${PORTNAME}
INFO=		cronolog
PLIST_FILES=	sbin/cronolog \
		sbin/cronosplit \
		share/man/man1/cronolog.1m.gz \
		share/man/man1/cronosplit.1m.gz

.include <bsd.port.mk>
