# Created by: gugu
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-AutoCRUD
PORTVERSION=	2.131.210
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Instant AJAX web front-end for DBIx::Class

BUILD_DEPENDS=	p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Model-DBIC-Schema>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Plugin-ConfigLoader>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Runtime>=5.70000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-View-JSON>=0:${PORTSDIR}/www/p5-Catalyst-View-JSON \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-DBIx-Class-Schema-Loader>=0:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
		p5-Data-Page>=0:${PORTSDIR}/databases/p5-Data-Page \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Lingua-EN-Inflect-Number>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
