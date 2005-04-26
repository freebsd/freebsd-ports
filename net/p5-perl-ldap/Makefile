# New ports collection makefile for:	perl-ldap
# Date created:	October 27th 2000
# Whom:		scrappy@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	perl-ldap
PORTVERSION=	${DISTVERSION:S/.././g}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${DISTVERSION:S/..//g}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Client interface to LDAP servers

DISTVERSION=	0.33

BUILD_DEPENDS=	${SITE_PERL}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${SITE_PERL}/URI/ldap.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/XML/SAX/Base.pm:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Bundle::Net::LDAP.3 \
		Net::LDAP.3 \
		Net::LDAP::Constant.3 \
		Net::LDAP::Control.3 \
		Net::LDAP::Control::EntryChange.3 \
		Net::LDAP::Control::ManageDsaIT.3 \
		Net::LDAP::Control::Paged.3 \
		Net::LDAP::Control::PersistentSearch.3 \
		Net::LDAP::Control::ProxyAuth.3 \
		Net::LDAP::Control::Sort.3 \
		Net::LDAP::Control::SortResult.3 \
		Net::LDAP::Control::VLV.3 \
		Net::LDAP::Control::VLVResponse.3 \
		Net::LDAP::DSML.3 \
		Net::LDAP::Entry.3 \
		Net::LDAP::Examples.3 \
		Net::LDAP::Extension::SetPassword.3 \
		Net::LDAP::Extension::WhoAmI.3 \
		Net::LDAP::Extra.3 \
		Net::LDAP::FAQ.3 \
		Net::LDAP::Filter.3 \
		Net::LDAP::LDIF.3 \
		Net::LDAP::Message.3 \
		Net::LDAP::RFC.3 \
		Net::LDAP::Reference.3 \
		Net::LDAP::RootDSE.3 \
		Net::LDAP::Schema.3 \
		Net::LDAP::Search.3 \
		Net::LDAP::Security.3 \
		Net::LDAP::Util.3 \
		Net::LDAPI.3 \
		Net::LDAPS.3

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -ni'.bak' -e 'next if 2../^__END__$$/; print' \
		'${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}'

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
