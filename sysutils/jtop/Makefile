# Created by: Pavel Novikov
# $FreeBSD$

PORTNAME=	jtop
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ext.by/jtop/

MAINTAINER=	pavel@ext.by
COMMENT=	Wrapper to top(1) that maps pids to jails

BUILD_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
PLIST_FILES=	bin/jtop man/man1/jtop.1.gz
SHEBANG_FILES= 	jtop.pl

.include <bsd.port.mk>
