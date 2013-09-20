# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	FormValidator-Lite
PORTVERSION=	0.37
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Lightleight form validation library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
		p5-Class-Load>=0.11:${PORTSDIR}/devel/p5-Class-Load \
		p5-Email-Valid>0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Email-Valid-Loose>0:${PORTSDIR}/mail/p5-Email-Valid-Loose \
		p5-Filter>0:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Text-TestBase>0:${PORTSDIR}/textproc/p5-Text-TestBase \
		p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	modbuild

MAN3=		FormValidator::Lite.3 \
		FormValidator::Lite::Constraint.3 \
		FormValidator::Lite::Constraint::Date.3 \
		FormValidator::Lite::Constraint::Default.3 \
		FormValidator::Lite::Constraint::Email.3 \
		FormValidator::Lite::Constraint::File.3 \
		FormValidator::Lite::Constraint::Japanese.3 \
		FormValidator::Lite::Constraint::Number.3 \
		FormValidator::Lite::Constraint::Time.3 \
		FormValidator::Lite::Constraint::URL.3 \
		FormValidator::Lite::Messages::en.3 \
		FormValidator::Lite::Messages::ja.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
