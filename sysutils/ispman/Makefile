# New ports collection makefile for:	ispman
# Date created:		Wed Sep 26 20:23:38 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	ispman
PORTVERSION=	1.3r2
CATEGORIES=	sysutils perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.3
DISTNAME=	${PORTNAME}-1.3rc2

MAINTAINER=	dsh@vlink.ru
COMMENT=	ISP management software

RUN_DEPENDS=	${SITE_PERL}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced\
		${SITE_PERL}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/Digest/base.pm:${PORTSDIR}/security/p5-Digest \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/Log/Agent.pm:${PORTSDIR}/devel/p5-Log-Agent \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/CGI/Session.pm:${PORTSDIR}/www/p5-CGI-Session \
		${SITE_PERL}/IMAP/Admin.pm:${PORTSDIR}/mail/p5-IMAP-Admin \
		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/DNS/ZoneParse.pm:${PORTSDIR}/dns/p5-DNS-ZoneParse \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/Mail/RFC822/Address.pm:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
		${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext \
		${SITE_PERL}/Locale/Maketext/Lexicon.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		${SITE_PERL}/I18N/LangTags.pm:${PORTSDIR}/misc/p5-I18N-LangTags \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite

USE_GMAKE=	yes
USE_PERL5=	yes

ALL_TARGET=	ispman
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/${PORTNAME}

MAKE_ENV+=	DATA_MODES="-c ${_SHROWNGRP} -m ${SHAREMODE}" \
		SCRIPT_MODES="-c ${_BINOWNGRP} -m ${BINMODE}"
WRKSRC=		${WRKDIR}/${PORTNAME}-1.3

post-patch:
	${GREP} -FlR '/usr/bin/perl' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' -e 's!/usr/bin/perl!${PERL}!'
	${FIND} -d ${WRKSRC}/docs -name CVS -exec ${RM} -rf {} +

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
