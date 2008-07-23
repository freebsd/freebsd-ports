# New ports collection makefile for:   qpsmtpd
# Date created:        1 January 2007
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	qpsmtpd
PORTVERSION=	0.40
PORTREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	http://smtpd.develooper.com/files/
PKGNAMEPREFIX=	p5-
DISTNAME=	qpsmtpd-${PORTVERSION}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A flexible SMTP daemon written in Perl and featuring a plugin API

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		spamd:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS/Resolver.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/${PERL_ARCH}/Geo/IP.pm:${PORTSDIR}/net/p5-Geo-IP \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Digest/HMAC_MD5.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		clamd:${PORTSDIR}/security/clamav

WRKSRC=		${WRKDIR}/${DISTNAME}
PERL_CONFIGURE=	yes

MAN3=		Qpsmtpd::Command.3 \
		Qpsmtpd::Constants.3 \
		Qpsmtpd::DSN.3 \
		Qpsmtpd::ConfigServer.3 \
		Qpsmtpd::Transaction.3 \
		Qpsmtpd::Address.3 \
		Qpsmtpd.3 \
		Qpsmtpd::Connection.3 \
		Qpsmtpd::Postfix.3 \
		Apache::Qpsmtpd.3

USE_RC_SUBR=	qpsmtpd.sh

pre-configure:
	@${RM} ${WRKSRC}/plugins/milter

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/plugins
	@(cd ${WRKSRC}/plugins/ && ${COPYTREE_SHARE} \* ${DATADIR}/plugins/)
	@(cd ${WRKSRC}/config.sample/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}/
.endif
	@${ECHO_MSG}
	@${ECHO_MSG}
	@${ECHO_MSG} '*****************************************************************'
	@${ECHO_MSG}
	@${ECHO_MSG} "Please read http://wiki.qpsmtpd.org/ for more info about"
	@${ECHO_MSG} "installation."
	@${ECHO_MSG}
	@${ECHO_MSG} "The example config can be found in "${PREFIX}"/share/examples/"${PORTNAME}"/"
	@${ECHO_MSG}
	@${ECHO_MSG} "The plugins can be found in "${PREFIX}"/share/"${PORTNAME}"/plugins/"
	@${ECHO_MSG}
	@${ECHO_MSG} "This port does also not make any assumptions about what user you"
	@${ECHO_MSG} "wish to use or install location."
	@${ECHO_MSG}
	@${ECHO_MSG} '*****************************************************************'

.include <bsd.port.mk>
