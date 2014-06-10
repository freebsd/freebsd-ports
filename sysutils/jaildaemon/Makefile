# Created by: Dirk Engling <erdgeist@erdgeist.org>
# $FreeBSD$

PORTNAME=	jaildaemon
PORTVERSION=	0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/jaildaemon/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Fixed command-line interface for FreeBSD jails to their host system

USES=		tar:bzip2

PLIST_FILES=	bin/jaildaemon \
		etc/rc.d/jaildaemon \
		man/man1/jaildaemon.1.gz

MAKE_ENV=	DESTDIR=${STAGEDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires jail_get function from FreeBSD 8
.endif

.include <bsd.port.post.mk>
