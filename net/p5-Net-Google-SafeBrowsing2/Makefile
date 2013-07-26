# Created by: Alexandre Biancalana <ale@biancalanas.net>
# $FreeBSD$

PORTNAME=	Net-Google-SafeBrowsing2
PORTVERSION=	1.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ale@biancalanas.net
COMMENT=	Perl extension for the Google Safe Browsing v2 API

BUILD_DEPENDS=	p5-libwww>=5:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1:${PORTSDIR}/net/p5-URI \
		p5-Digest-SHA>=5:${PORTSDIR}/security/p5-Digest-SHA \
		p5-Net-IPAddress>=1:${PORTSDIR}/net-mgmt/p5-Net-IPAddress \
		p5-Text-Trim>=1:${PORTSDIR}/textproc/p5-Text-Trim \
		p5-MIME-Base64>=3:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-MIME-Base64-URLSafe>=0.01:${PORTSDIR}/converters/p5-MIME-Base64-URLSafe \
		p5-Digest-HMAC>=1:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-String-HexConvert>=0.01:${PORTSDIR}/textproc/p5-String-HexConvert \
		p5-File-Slurp>9:${PORTSDIR}/devel/p5-File-Slurp

RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	MySQL SQLite Postgres

MySQL_DESC=	uses MySQL as the storage backend
SQLite_DESC=	uses SQLite as the storage backend
Postgres_DESC=	uses Postgres as the storage backend

OPTIONS_DEFAULT=SQLite

PERL_CONFIGURE=	yes

MAN3=	Net::Google::SafeBrowsing2::Storage.3 \
	Net::Google::SafeBrowsing2::Lookup.3 \
	Net::Google::SafeBrowsing2::Postgres.3 \
	Net::Google::SafeBrowsing2.3 \
	Net::Google::SafeBrowsing2::DBI.3 \
	Net::Google::SafeBrowsing2::MySQL.3 \
	Net::Google::SafeBrowsing2::Sqlite.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLite}
BUILD_DEPENDS+=	p5-DBD-SQLite>=1:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS+=	p5-DBD-SQLite>=1:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

.if ${PORT_OPTIONS:MMySQL}
BUILD_DEPENDS+=	p5-DBD-mysql>=4:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS+=	p5-DBD-mysql>=4:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPostgres}
BUILD_DEPENDS+=	p5-DBD-Pg>=2:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS+=	p5-DBD-Pg>=2:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.include <bsd.port.mk>
