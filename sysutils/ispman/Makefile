# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	ispman
PORTVERSION=	1.3r2
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.3
DISTNAME=	${PORTNAME}-1.3rc2

MAINTAINER=	dsh@vlink.ru
COMMENT=	ISP management software

RUN_DEPENDS=	p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced\
		p5-Convert-ASN1>=0:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Log-Agent>=0:${PORTSDIR}/devel/p5-Log-Agent \
		p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-IMAP-Admin>=0:${PORTSDIR}/mail/p5-IMAP-Admin \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-DNS-ZoneParse>=0:${PORTSDIR}/dns/p5-DNS-ZoneParse \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-Mail-RFC822-Address>=0:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-I18N-LangTags>=0:${PORTSDIR}/misc/p5-I18N-LangTags \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite

USES=		perl5 gmake

ALL_TARGET=	ispman
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/${PORTNAME}

MAKE_ENV+=	DATA_MODES="-c ${_SHROWNGRP} -m ${SHAREMODE}" \
		SCRIPT_MODES="-c ${_BINOWNGRP} -m ${BINMODE}"
WRKSRC=		${WRKDIR}/${PORTNAME}-1.3

NO_STAGE=	yes
post-patch:
	${GREP} -FlR '/usr/bin/perl' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' -e 's!/usr/bin/perl!${PERL}!'
	${FIND} -d ${WRKSRC}/docs -name CVS -exec ${RM} -rf {} +

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
