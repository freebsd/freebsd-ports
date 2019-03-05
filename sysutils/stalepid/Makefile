# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	stalepid
PORTVERSION=	1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	https://devel.ringlet.net/files/sys/stalepid/

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	Check for stale pid files and remove them

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	p5-Error>=0:lang/p5-Error

USES=		perl5 shebangfix uidfix
USE_PERL5=	run

SHEBANG_FILES=	${WRKSRC}/stalepid.pl

PLIST_FILES=	bin/stalepid man/man1/stalepid.1.gz

.include <bsd.port.mk>
