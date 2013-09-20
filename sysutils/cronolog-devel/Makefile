# $FreeBSD$

PORTNAME=	cronolog
PORTVERSION=	1.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://cronolog.org/patches/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web log rotation utility that provides datestamp filenames

PLIST_FILES=	sbin/cronolog \
		sbin/cronosplit

CONFLICTS=	cronolog-[0-9]*

WRKSRC=		${WRKDIR}/cronolog-${PORTVERSION}
INFO=		cronolog
MAN1=		cronolog.1m cronosplit.1m

GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
