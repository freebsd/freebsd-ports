# Created by: Ryan Steinmetz
# $FreeBSD$

PORTNAME=	check_email_delivery
PORTVERSION=	0.7.1b
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://buhacoff.net/software/check_email_delivery/archive/ \
		http://mirrors.rit.edu/zi/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Nagios Plugin to monitor your mail environment

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	p5-Net-SMTP-TLS>=0:mail/p5-Net-SMTP-TLS \
		p5-Net-DNS>0:dns/p5-Net-DNS \
		p5-Email-Address>0:mail/p5-Email-Address \
		p5-Mail-IMAPClient>=0:mail/p5-Mail-IMAPClient

USES=		perl5 shebangfix
SCRIPTS=	check_email_delivery check_email_delivery_epn \
		check_imap_quota check_imap_quota_epn \
		check_imap_receive check_imap_receive_epn \
		check_smtp_send check_smtp_send_epn \
		imap_ssl_cert imap_ssl_cert_epn
SHEBANG_FILES=	${SCRIPTS}
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
DOC_FILES=	check_email_delivery.html check_email_delivery.pod \
		check_imap_receive.html check_imap_receive.pod \
		check_smtp_send.html check_smtp_send.pod \
		check_imap_quota.html check_imap_quota.pod \
		imap_ssl_cert.html imap_ssl_cert.pod

PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/nagios/libexec|${PREFIX}/libexec/nagios|' \
		${WRKSRC}/check_email_delivery* ${WRKSRC}/docs/*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
.for file in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/libexec/nagios/
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
