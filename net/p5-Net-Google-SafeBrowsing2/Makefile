# Created by: Alexandre Biancalana <ale@biancalanas.net>
# $FreeBSD$

PORTNAME=	Net-Google-SafeBrowsing2
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ale@biancalanas.net
COMMENT=	Perl extension for the Google Safe Browsing v2 API

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-libwww>=5:www/p5-libwww \
		p5-URI>=1:net/p5-URI \
		p5-Net-IPAddress>=1:net-mgmt/p5-Net-IPAddress \
		p5-Text-Trim>=1:textproc/p5-Text-Trim \
		p5-MIME-Base64-URLSafe>=0.01:converters/p5-MIME-Base64-URLSafe \
		p5-Digest-HMAC>=1:security/p5-Digest-HMAC \
		p5-String-HexConvert>=0.01:textproc/p5-String-HexConvert \
		p5-File-Slurp>9:devel/p5-File-Slurp


OPTIONS_DEFINE=	MySQL SQLite Postgres

MySQL_DESC=	uses MySQL as the storage backend
SQLite_DESC=	uses SQLite as the storage backend
Postgres_DESC=	uses Postgres as the storage backend

OPTIONS_DEFAULT=SQLite

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

MySQL_BUILD_DEPENDS=	p5-DBD-mysql>=4:databases/p5-DBD-mysql
MySQL_RUN_DEPENDS=	p5-DBD-mysql>=4:databases/p5-DBD-mysql
Postgres_BUILD_DEPENDS=	p5-DBD-Pg>=2:databases/p5-DBD-Pg
Postgres_RUN_DEPENDS=	p5-DBD-Pg>=2:databases/p5-DBD-Pg
SQLite_BUILD_DEPENDS=	p5-DBD-SQLite>=1:databases/p5-DBD-SQLite
SQLite_RUN_DEPENDS=	p5-DBD-SQLite>=1:databases/p5-DBD-SQLite

.include <bsd.port.mk>
