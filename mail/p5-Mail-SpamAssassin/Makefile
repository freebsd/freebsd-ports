# New ports collection makefile for:	p5-Mail-SpamAssassin
# Date created:				Nov 26 2001
# Whom:					Anthony Kim
#
# $FreeBSD$
#

PORTNAME=	Mail-SpamAssassin
PORTVERSION=	2.41
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://spamassassin.org/released/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	alane@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		razor-client:${PORTSDIR}/mail/razor-agents

PODPARSER=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser
RUN_DEPENDS+=	${PODPARSER}
BUILD_DEPENDS+=	${PODPARSER}

PERL_CONFIGURE=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::SpamAssassin.3 Mail::SpamAssassin::PerMsgStatus.3 \
		Mail::SpamAssassin::Conf.3 \
		Mail::SpamAssassin::PersistentAddrList.3
MAN1PREFIX=	${PREFIX}
MAN1=		spamd.1 spamassassin.1 spamc.1
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples//${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete

post-install:
	@strip ${PREFIX}/bin/spamc
	${INSTALL_SCRIPT} ${FILESDIR}/spamd.sh ${PREFIX}/etc/rc.d/spamd.sh-dist

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sql/README ${DOCSDIR}/README.sql
	cd ${WRKSRC} ; ${INSTALL_DATA} \
	    BUGS COPYRIGHT Changes README TRADEMARK procmailrc.example sample* \
	    spamd/README* sql/spamassassin.sql \
	    ${DOCSDIR}
.endif

.include <bsd.port.mk>
