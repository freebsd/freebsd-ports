# Created by: Steve Atwell
# $FreeBSD$

PORTNAME=	slack
PORTVERSION=	0.15.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://www.sundell.net/~alan/projects/slack/

MAINTAINER=	satwell@disjoint.net
COMMENT=	Configuration management system designed to appeal to lazy admins

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USES=		perl5 gmake

MAN1=		slack-diff.1
MAN5=		slack.conf.5
MAN8=		slack.8

PORTDOCS=	ChangeLog COPYING CREDITS FAQ GPL README TODO \
		fixfiles-and-dirs.txt slack-intro

MAKE_ARGS=	prefix=${PREFIX} exec_prefix=${PREFIX} \
		libexecdir=${PREFIX}/libexec mandir=${PREFIX}/man \
		localstatedir=/var

NO_STAGE=	yes
pre-build:
	${REINPLACE_CMD} -e '1s,^#!.*perl,#!${PERL},' ${WRKSRC}/test/gen_config_file
	
post-build:
	@for f in ${WRKSRC}/src/build/*; do \
		${REINPLACE_CMD} -e '1s,^#!.*perl,#!${PERL},' $$f; \
	done

post-install:
	@${INSTALL_DATA} ${WRKSRC}/src/build/slack.conf ${PREFIX}/etc/slack.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/GPL ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/fixfiles-and-dirs.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/slack-intro ${DOCSDIR}
.endif

.include <bsd.port.mk>
