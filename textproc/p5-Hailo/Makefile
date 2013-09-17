# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	Hailo
PORTVERSION=	0.70
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HINRIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	A pluggable Markov engine analogous to MegaHAL

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Bot-Training-MegaHAL>=0:${PORTSDIR}/misc/p5-Bot-Training-MegaHAL \
		p5-Bot-Training-StarCraft>=0:${PORTSDIR}/misc/p5-Bot-Training-StarCraft \
		p5-Bot-Training>=0:${PORTSDIR}/misc/p5-Bot-Training \
		p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load \
		p5-Data-Dump>=1.17:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Data-Section>=0.101620:${PORTSDIR}/devel/p5-Data-Section \
		p5-Dir-Self>=0.10:${PORTSDIR}/devel/p5-Dir-Self \
		p5-File-CountLines>=0.0.2:${PORTSDIR}/devel/p5-File-CountLines \
		p5-Getopt-Long-Descriptive>=0.085:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-IO-Interactive>=0.0.6:${PORTSDIR}/devel/p5-IO-Interactive \
		p5-IPC-System-Simple>=1.21:${PORTSDIR}/devel/p5-IPC-System-Simple \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MooseX-StrictConstructor>=0.16:${PORTSDIR}/devel/p5-MooseX-StrictConstructor \
		p5-MouseX-Getopt>=0.33:${PORTSDIR}/devel/p5-MouseX-Getopt \
		p5-MouseX-StrictConstructor>=0.02:${PORTSDIR}/devel/p5-MouseX-StrictConstructor \
		p5-Regexp-Common>=2010010201:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Term-Sk>=0.06:${PORTSDIR}/devel/p5-Term-Sk \
		p5-namespace-clean>=0.18:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=1.29:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-Exception>=0.29:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Expect>=0.31:${PORTSDIR}/devel/p5-Test-Expect \
		p5-Test-Output>=0.16:${PORTSDIR}/devel/p5-Test-Output \
		p5-Test-Script>=1.07:${PORTSDIR}/devel/p5-Test-Script \
		p5-Test-Script-Run>=0.04:${PORTSDIR}/devel/p5-Test-Script-Run \
		p5-Test-Synopsis>=0.06:${PORTSDIR}/devel/p5-Test-Synopsis

USES=		perl5
USE_PERL5=	configure

MAN1=		hailo.1

MAN3=		Hailo.3 \
		Hailo::Command.3 \
		Hailo::Engine::Default.3 \
		Hailo::Engine::Scored.3 \
		Hailo::Role::Arguments.3 \
		Hailo::Role::Engine.3 \
		Hailo::Role::Storage.3 \
		Hailo::Role::Tokenizer.3 \
		Hailo::Role::UI.3 \
		Hailo::Storage.3 \
		Hailo::Storage::MySQL.3 \
		Hailo::Storage::PostgreSQL.3 \
		Hailo::Storage::SQLite.3 \
		Hailo::Storage::Schema.3 \
		Hailo::Tokenizer::Chars.3 \
		Hailo::Tokenizer::Words.3 \
		Hailo::UI::ReadLine.3

OPTIONS_DEFINE=	SQLITE PGSQL MYSQL
OPTIONS_DEFAULT=	SQLITE

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	p5-DBD-SQLite>=1.29:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-autodie>=2.08:${PORTSDIR}/devel/p5-autodie
RUN_DEPENDS+=	p5-autodie>=2.08:${PORTSDIR}/devel/p5-autodie
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
