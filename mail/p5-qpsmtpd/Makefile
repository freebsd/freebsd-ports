# New ports collection makefile for:   qpsmtpd
# Date created:        1 January 2007
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	qpsmtpd
PORTVERSION=	0.84
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://smtpd.develooper.com/files/
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A flexible SMTP daemon written in Perl and featuring a plugin API

RUN_DEPENDS=	spamd:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2

MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
PERL_CONFIGURE=	yes

MAN1=	qpsmtpd-async.1
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

USE_RC_SUBR=	qpsmtpd

SUB_LIST+=	PERL=${PERL}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES+=	pkg-message

pre-configure:
	@${RM} ${WRKSRC}/plugins/milter

post-install:
	@${MKDIR} ${DATADIR}/
	@${MKDIR} ${DATADIR}/plugins
	@(cd ${WRKSRC}/plugins/ && ${COPYTREE_SHARE} \* ${DATADIR}/plugins/)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
	@(cd ${WRKSRC}/config.sample/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
