# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bayespam
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://BSDforge.com/projects/source/mail/bayespam/
EXTRACT_SUFX=	.tar_.gz

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Qmail spam filter written in Perl using Bayesian classification

LICENSE=	GPLv2

RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools

USES=		shebangfix perl5
NO_BUILD=	yes

SHEBANG_FILES=	*.pl

FILES_DOCS=	AUTHORS COPYING Changelog INSTALL README TODO \
		qmail.sample
FILES_SCRIPTS=	bayes_process_email.pl bayes_spam_check.pl bayestest.pl

OPTIONS_DEFINE=	DOCS

post-patch:
# fix location of Bayesian filter
	@${REINPLACE_CMD} -e 's|/user/|${PREFIX}/|' ${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|' \
		${WRKSRC}/qmail.sample
	@${REINPLACE_CMD} -E -e \
		's|/usr/bin/(bayes_spam_check.pl)|${PREFIX}/bin/\1|' \
		${WRKSRC}/bayestest.pl

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILES_DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Bayespam
	${INSTALL_DATA} ${WRKSRC}/Bayespam/Process.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Bayespam
	${INSTALL_SCRIPT} ${FILES_SCRIPTS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
