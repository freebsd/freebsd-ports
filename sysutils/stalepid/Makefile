# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	stalepid
PORTVERSION=	1.0.b1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/stalepid/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check for stale pid files and remove them

RUN_DEPENDS=	p5-Error>=0:lang/p5-Error

USES=		perl5 shebangfix uidfix
USE_PERL5=	run
SHEBANG_FILES=	${WRKSRC}/stalepid.pl

PLIST_FILES=	bin/stalepid man/man1/stalepid.1.gz

.include <bsd.port.mk>
