# New ports collection makefile for:	perl-ldap
# Date created:	October 27th 2000
# Whom:		scrappy@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	perl-ldap
PORTVERSION=	0.22
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	scrappy@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI/ldap.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::LDAP::Control::VLVResponse.3 \
		Net::LDAP::Entry.3 \
		Net::LDAP::Control::Sort.3 \
		Net::LDAP::Util.3 \
		Authen::SASL.3 \
		Bundle::Net::LDAP.3 \
		Net::LDAP::Search.3 \
		Net::LDAP::Control::SortResult.3 \
		Net::LDAP::LDIF.3 \
		Net::LDAP::Schema.3 \
		Net::LDAP::Filter.3 \
		Net::LDAP::Examples.3 \
		Net::LDAP::Control::VLV.3 \
		Net::LDAPS.3 \
		Net::LDAP::FAQ.3 \
		Net::LDAP::Control.3 \
		Net::LDAP::Control::Paged.3 \
		Net::LDAP.3 \
		Net::LDAP::DSML.3 \
		Net::LDAP::Message.3 \
		Net::LDAP::Constant.3 \
		Net::LDAP::Reference.3 \
		Net::LDAP::RFC.3

.include <bsd.port.mk>
