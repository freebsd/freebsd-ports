# Created by: gmc@sonologic.nl
# $FreeBSD$

PORTNAME=	Mail-SPF
PORTVERSION=	2.007
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reference implementation of the RFC 4408 SPF protocol

RUN_DEPENDS=	p5-Net-DNS-Resolver-Programmable>=0.002.1:${PORTSDIR}/dns/p5-Net-DNS-Resolver-Programmable \
		p5-Net-DNS>=0.58:${PORTSDIR}/dns/p5-Net-DNS \
		p5-version>0:${PORTSDIR}/devel/p5-version \
		p5-Error>0:${PORTSDIR}/lang/p5-Error \
		p5-NetAddr-IP>=4:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-URI>=1.13:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	p5-Mail-SPF-Query-[0-9]*

PERL_MODBUILD=	yes
CONFIGURE_ARGS=	--install_path sbin=${PREFIX}/sbin

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

OPTIONS_DEFINE=	SPFQUERY SPFQUERY_SUFFIX DOCS
SPFQUERY_DESC=	Install spfquery command-line tool
SPFQUERY_SUFFIX_DESC=Add .pl suffix to spfquery
OPTIONS_DEFAULT=SPFQUERY SPFQUERY_SUFFIX

.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/p5-Mail-SPF
DOCS=		CHANGES INSTALL LICENSE README TODO

.if ${PORT_OPTIONS:MSPFQUERY}
PLIST_SUB+=	SPFQUERY=""

.if ${PORT_OPTIONS:MSPFQUERY_SUFFIX}
PLIST_SUB+=	SPFQUERY_SUFFIX=".pl"
MAN1+=		spfquery.pl.1
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-spfquery-suffix
post-extract:
	${MV} ${WRKSRC}/bin/spfquery ${WRKSRC}/bin/spfquery.pl
.else
PLIST_SUB+=	SPFQUERY_SUFFIX=""
MAN1+=		spfquery.1
CONFLICTS+=	libspf2-[0-9]*
.endif

.else
PLIST_SUB+=	SPFQUERY="@comment "
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-no-spfquery
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
