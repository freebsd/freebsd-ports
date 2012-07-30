# New ports collection makefile for:   WebDAO
# Date created:        27 Mach 2012
# Whom:                Zahatski Aliaksandr <zag@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	WebDAO
PORTVERSION=	2.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZAG
PKGNAMEPREFIX=	p5-

MAINTAINER=	zag@cpan.org
COMMENT=	Platform for easy creation of web applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0.37:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-HTTP>=0.37:${PORTSDIR}/devel/p5-DateTime-Format-HTTP \
		p5-FCGI>=0.67:${PORTSDIR}/www/p5-FCGI \
		p5-HTTP-Body>=1.11:${PORTSDIR}/www/p5-HTTP-Body \
		p5-URI>=1.36:${PORTSDIR}/net/p5-URI \
		p5-XML-Flow>=0.86:${PORTSDIR}/textproc/p5-XML-Flow
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class

PERL_CONFIGURE=	yes

MAN1=		wd_fcgi.fpl.1 \
		wd_shell.pl.1
MAN3=		WebDAO.3 \
		WebDAO::Base.3 \
		WebDAO::CV.3 \
		WebDAO::CVfcgi.3 \
		WebDAO::Component.3 \
		WebDAO::Config.3 \
		WebDAO::Container.3 \
		WebDAO::Element.3 \
		WebDAO::Engine.3 \
		WebDAO::FCGI::ProcManager.3 \
		WebDAO::Lex.3 \
		WebDAO::Lexer::base.3 \
		WebDAO::Lexer::method.3 \
		WebDAO::Lexer::object.3 \
		WebDAO::Lexer::regclass.3 \
		WebDAO::Lexer::text.3 \
		WebDAO::Lib::MethodByPath.3 \
		WebDAO::Lib::RawHTML.3 \
		WebDAO::Response.3 \
		WebDAO::Session.3 \
		WebDAO::SessionSH.3 \
		WebDAO::Sessionco.3 \
		WebDAO::Store::Abstract.3 \
		WebDAO::Store::Storable.3 \
		WebDAO::Test.3 \
		WebDAO::Util.3

# maintainer section:
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
