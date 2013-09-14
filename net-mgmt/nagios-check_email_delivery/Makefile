# New ports collection makefile for:	nagios-check_email_delivery
# Date created: 	9 May 2011
# Whom:			Ryan Steinmetz
#
# $FreeBSD$

PORTNAME=	check_email_delivery
PORTVERSION=	0.7.1b
CATEGORIES=	net-mgmt
MASTER_SITES=	http://buhacoff.net/software/check_email_delivery/archive/ \
		http://mirrors.rit.edu/zi/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Nagios Plugin to monitor your mail environment

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	p5-Net-SMTP-TLS>=0:${PORTSDIR}/mail/p5-Net-SMTP-TLS \
		p5-Mail-IMAPClient>=0:${PORTSDIR}/mail/p5-Mail-IMAPClient

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
DOC_FILES=	check_email_delivery.html check_email_delivery.pod \
		check_imap_receive.html check_imap_receive.pod \
		check_smtp_send.html check_smtp_send.pod \
		check_imap_quota.html check_imap_quota.pod \
		imap_ssl_cert.html imap_ssl_cert.pod

PORTSCOUT=	ignore:1

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_email_delivery ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_email_delivery_epn ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_imap_quota ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_imap_quota_epn ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_imap_receive ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_imap_receive_epn ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_smtp_send ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_smtp_send_epn ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/imap_ssl_cert ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/imap_ssl_cert_epn ${PREFIX}/libexec/nagios/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
