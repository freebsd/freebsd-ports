# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	asql
PORTVERSION=	1.7
CATEGORIES=	www
MASTER_SITES=	http://www.steve.org.uk/Software/asql/ \
		http://www.c-s.li/ports/

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Query Apache logfiles via SQL

RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-ReadLine-Perl>=0:devel/p5-ReadLine-Perl

NO_BUILD=	yes
PLIST_FILES=	bin/asql
USES=		perl5 shebangfix
SHEBANG_FILES=	bin/asql
.include <bsd.port.mk>
