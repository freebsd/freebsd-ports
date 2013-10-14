# Created by: gmc@sonologic.nl
# $FreeBSD$

PORTNAME=	Mail-SPF
PORTVERSION=	2.9.0
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented implementation of Sender Policy Framework

LICENSE=	BSD

BUILD_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Net-DNS>=0.62:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS-Resolver-Programmable>=0.003:${PORTSDIR}/dns/p5-Net-DNS-Resolver-Programmable \
		p5-NetAddr-IP>=4:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-URI>=1.13:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

CONFLICTS_INSTALL=	p5-Mail-SPF-Query-[0-9]*

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--install_path sbin=${PREFIX}/sbin
NO_STAGE=	yes
USE_PERL5=	modbuild
USES=		perl5

DOCSDIR=	${PREFIX}/share/doc/p5-Mail-SPF
MAN1=		spfquery.pl.1
MAN3=		Mail::SPF.3 Mail::SPF::Mech::PTR.3 Mail::SPF::Mech.3 \
		Mail::SPF::SenderIPAddrMech.3 Mail::SPF::MacroString.3 \
		Mail::SPF::Mech::IP4.3 Mail::SPF::Mech::A.3 \
		Mail::SPF::Request.3 Mail::SPF::Result.3 Mail::SPF::Mod.3 \
		Mail::SPF::Mod::Exp.3 Mail::SPF::Mech::MX.3 \
		Mail::SPF::Server.3 Mail::SPF::Util.3 Mail::SPF::Mech::IP6.3 \
		Mail::SPF::Record.3 Mail::SPF::Mech::Include.3 \
		Mail::SPF::v2::Record.3 Mail::SPF::Mod::Redirect.3 \
		Mail::SPF::Base.3 Mail::SPF::Mech::All.3 Mail::SPF::Term.3 \
		Mail::SPF::v1::Record.3 Mail::SPF::Mech::Exists.3
PORTDOCS=	CHANGES README TODO

.include <bsd.port.options.mk>

post-patch:
	@${MV} ${WRKSRC}/sbin/spfd ${WRKSRC}/sbin/spfd.pl
	@${MV} ${WRKSRC}/bin/spfquery ${WRKSRC}/bin/spfquery.pl
	@${REINPLACE_CMD} -e 's|spfd|&.pl|; s|spfquery|&.pl|' ${WRKSRC}/Build.PL ${WRKSRC}/MANIFEST ${WRKSRC}/README

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
