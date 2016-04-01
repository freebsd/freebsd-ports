# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	Hailo
PORTVERSION=	0.70
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HINRIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pluggable Markov engine analogous to MegaHAL

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0.13:devel/p5-Any-Moose \
		p5-Bot-Training-MegaHAL>=0:misc/p5-Bot-Training-MegaHAL \
		p5-Bot-Training-StarCraft>=0:misc/p5-Bot-Training-StarCraft \
		p5-Bot-Training>=0:misc/p5-Bot-Training \
		p5-Class-Load>=0.06:devel/p5-Class-Load \
		p5-Data-Dump>=1.17:devel/p5-Data-Dump \
		p5-Data-Section>=0.101620:devel/p5-Data-Section \
		p5-Dir-Self>=0.10:devel/p5-Dir-Self \
		p5-File-CountLines>=0.0.2:devel/p5-File-CountLines \
		p5-Getopt-Long-Descriptive>=0.085:devel/p5-Getopt-Long-Descriptive \
		p5-IO-Interactive>=0.0.6:devel/p5-IO-Interactive \
		p5-IPC-System-Simple>=1.21:devel/p5-IPC-System-Simple \
		p5-List-MoreUtils>=0.22:lang/p5-List-MoreUtils \
		p5-MooseX-StrictConstructor>=0.16:devel/p5-MooseX-StrictConstructor \
		p5-MouseX-Getopt>=0.33:devel/p5-MouseX-Getopt \
		p5-MouseX-StrictConstructor>=0.02:devel/p5-MouseX-StrictConstructor \
		p5-Regexp-Common>=2010010201:textproc/p5-Regexp-Common \
		p5-Term-Sk>=0.06:devel/p5-Term-Sk \
		p5-namespace-clean>=0.18:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=1.29:databases/p5-DBD-SQLite \
		p5-Test-Exception>=0.29:devel/p5-Test-Exception \
		p5-Test-Expect>=0.31:devel/p5-Test-Expect \
		p5-Test-Output>=0.16:devel/p5-Test-Output \
		p5-Test-Script>=1.07:devel/p5-Test-Script \
		p5-Test-Script-Run>=0.04:devel/p5-Test-Script-Run \
		p5-Test-Synopsis>=0.06:devel/p5-Test-Synopsis

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	SQLITE PGSQL MYSQL
OPTIONS_DEFAULT=	SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	p5-DBD-SQLite>=1.29:databases/p5-DBD-SQLite
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
.endif
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif

.include <bsd.port.mk>
