# New ports collection makefile for:	p5-Mail-SpamAssassin
# Date created:				Nov 26 2001
# Whom:					Anthony Kim
#
# $FreeBSD$
#

PORTNAME=	Mail-SpamAssassin
PORTVERSION=	2.01
PORTREVISION=   6
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::SpamAssassin.3 Mail::SpamAssassin::PerMsgStatus.3 \
		Mail::SpamAssassin::Conf.3 \
		Mail::SpamAssassin::PersistentAddrList.3 \
		Mail::SpamAssassin::SMTP::SmartHost.3
MAN1PREFIX=	${PREFIX}
MAN1=		spamd.1 spamassassin.1 spamc.1

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
	${INSTALL_DATA} ${WRKSRC}/spamd/README ${DOCSDIR}/spamd.README
	${INSTALL_DATA} ${WRKSRC}/spamproxy/README ${DOCSDIR}/spamproxy.README
	${INSTALL_DATA} ${WRKSRC}/sql/README ${DOCSDIR}/sql.README
	${INSTALL_DATA} ${WRKSRC}/sql/spamassassin.sql ${DOCSDIR}/spamassassin.sql
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
