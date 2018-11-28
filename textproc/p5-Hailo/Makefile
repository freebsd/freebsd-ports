# Created by: milki <milki@rescomp.berkeley.edu>
# $FreeBSD$

PORTNAME=	Hailo
PORTVERSION=	0.75
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AVAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pluggable Markov engine analogous to MegaHAL

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Dir-Self>=0:devel/p5-Dir-Self \
		p5-File-CountLines>=0:devel/p5-File-CountLines \
		p5-Getopt-Long-Descriptive>=0:devel/p5-Getopt-Long-Descriptive \
		p5-IO-Interactive>=0:devel/p5-IO-Interactive \
		p5-IPC-System-Simple>=0:devel/p5-IPC-System-Simple \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-MooseX-StrictConstructor>=0:devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Term-Sk>=0:devel/p5-Term-Sk \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Bot-Training>=0.06:misc/p5-Bot-Training \
		p5-Bot-Training-MegaHAL>=0.03:misc/p5-Bot-Training-MegaHAL \
		p5-Bot-Training-StarCraft>=0.03:misc/p5-Bot-Training-StarCraft \
		p5-Data-Section>=0:devel/p5-Data-Section \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Pod-Section>=0:textproc/p5-Pod-Section \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Expect>=0:devel/p5-Test-Expect \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Script>=0:devel/p5-Test-Script \
		p5-Test-Script-Run>=0:devel/p5-Test-Script-Run

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	SQLITE PGSQL MYSQL
OPTIONS_DEFAULT=SQLITE

SQLITE_RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql

.include <bsd.port.mk>
