# Created by: Pavel Novikov
# $FreeBSD$

PORTNAME=	jps
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ext.by/jps/

MAINTAINER=	pavel@ext.by
COMMENT=	Wrapper to ps(1) that maps pids to jails

BUILD_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
PLIST_FILES=	bin/jps man/man1/jps.1.gz
SHEBANG_FILES=	jps.pl

.include <bsd.port.mk>
