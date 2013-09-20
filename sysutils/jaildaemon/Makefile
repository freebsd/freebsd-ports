# Created by: Dirk Engling <erdgeist@erdgeist.org>
# $FreeBSD$

PORTNAME=	jaildaemon
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/jaildaemon/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Fixed command-line interface for FreeBSD jails to their host system

USE_BZIP2=	yes

PLIST_FILES=	bin/jaildaemon \
		etc/rc.d/jaildaemon
MAN1=		jaildaemon.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires jail_get function from FreeBSD 8
.endif

.include <bsd.port.post.mk>
