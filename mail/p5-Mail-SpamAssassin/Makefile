# New ports collection makefile for:	p5-Mail-SpamAssassin
# Date created:				Nov 26 2001
# Whom:					Anthony Kim
#
# $FreeBSD$
#

PORTNAME=	Mail-SpamAssassin
PORTVERSION=	2.64
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

PATCH_SITES=	http://www.habeas.com/files/
PATCHFILES=	SA-2.63-Habeas.diff
PATCH_DIST_STRIP=	-p0

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A highly efficient mail filter for identifying spam

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS} \
		razor-client:${PORTSDIR}/mail/razor-agents

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	SYSCONFDIR="${PREFIX}/etc" \
			RUN_RAZOR_TESTS="no" RUN_RAZOR2_TESTS="no" \
			CONTACT_ADDRESS="the administrator of that system"

MAN3=		Mail::SpamAssassin.3 Mail::SpamAssassin::PerMsgStatus.3 \
		Mail::SpamAssassin::Conf.3 \
		Mail::SpamAssassin::PersistentAddrList.3 \
		Mail::SpamAssassin::PerMsgLearner.3 \
		Mail::SpamAssassin::Bayes.3 \
		Mail::SpamAssassin::AutoWhitelist.3 \
		Mail::SpamAssassin::ConfSourceSQL.3

MAN1=		spamd.1 spamassassin.1 spamc.1 sa-learn.1

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/spamassassin

USE_RC_SUBR=	yes
SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_SUBR%%|${RC_SUBR}|g'
post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${MV} ${WRKSRC}/rules/local.cf ${WRKSRC}/rules/local.cf.sample
	@${SED} -e 's#local.cf#local.cf.sample#g' \
		${WRKSRC}/Makefile.PL > ${WRKSRC}/Makefile.PL.sed
	@${MV} ${WRKSRC}/Makefile.PL.sed ${WRKSRC}/Makefile.PL

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/spamd.sh > ${WRKDIR}/spamd.sh

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/spamc
	${INSTALL_SCRIPT} ${WRKDIR}/spamd.sh ${PREFIX}/etc/rc.d/spamd.sh
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sql/README ${DOCSDIR}/README.sql
	cd ${WRKSRC} ; ${INSTALL_DATA} INSTALL USAGE \
	    BUGS COPYRIGHT Changes README TRADEMARK procmailrc.example sample* \
	    spamd/README* sql/spamassassin.sql ${DOCSDIR}
.endif
	@${SED} -e 's#PREFIX#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
BUILD_DEPENDS+=	${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
