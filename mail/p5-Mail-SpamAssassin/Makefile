# New ports collection makefile for:	p5-Mail-SpamAssassin
# Date created:				Nov 26 2001
# Whom:					Anthony Kim
#
# $FreeBSD$
#

PORTNAME=	Mail-SpamAssassin
PORTVERSION=    2.11
PORTREVISION=   2
CATEGORIES=	mail perl5
MASTER_SITES=   http://spamassassin.org/released/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=  ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Razor/Client.pm:${PORTSDIR}/mail/razor-agents

PERL_CONFIGURE=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::SpamAssassin.3 Mail::SpamAssassin::PerMsgStatus.3 \
		Mail::SpamAssassin::Conf.3 \
		Mail::SpamAssassin::PersistentAddrList.3 \
		Mail::SpamAssassin::SMTP::SmartHost.3
MAN1PREFIX=	${PREFIX}
MAN1=           spamd.1 spamassassin.1 spamc.1 spamproxyd.1

post-patch:
	@find ${WRKSRC} -type f -name "*.orig" -exec rm -f "{}" ";"

post-install:
	strip ${PREFIX}/bin/spamc
	cd ${FILESDIR}; \
		${INSTALL_DATA} spamd.sh \
		${PREFIX}/etc/rc.d/spamd.sh-dist
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-nonspam.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-spam.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/spamd/README.spamd ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/spamproxy/README ${DOCSDIR}/README.spamproxy
	${INSTALL_DATA} ${WRKSRC}/sql/README ${DOCSDIR}/README.sql
	${INSTALL_DATA} ${WRKSRC}/sql/spamassassin.sql ${DOCSDIR}
.endif

.include <bsd.port.mk>
