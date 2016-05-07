# Created by: Steve Atwell
# $FreeBSD$

PORTNAME=	slack
PORTVERSION=	0.15.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE \
		http://www.sundell.net/~alan/projects/slack/

MAINTAINER=	satwell@disjoint.net
COMMENT=	Configuration management system designed to appeal to lazy admins

RUN_DEPENDS=	rsync:net/rsync

USES=		perl5 gmake
NO_ARCH=	yes

PORTDOCS=	ChangeLog COPYING CREDITS FAQ GPL README TODO \
		fixfiles-and-dirs.txt slack-intro
MAKE_ARGS=	prefix=${PREFIX} exec_prefix=${PREFIX} \
		libexecdir=${PREFIX}/libexec mandir=${PREFIX}/man \
		localstatedir=/var
OPTIONS_DEFINE=	DOCS

pre-build:
	${REINPLACE_CMD} -e '1s,^#!.*perl,#!${PERL},' ${WRKSRC}/test/gen_config_file

post-build:
	@for f in ${WRKSRC}/src/build/*; do \
		${REINPLACE_CMD} -e '1s,^#!.*perl,#!${PERL},' $$f; \
	done

post-install:
	@${INSTALL_DATA} ${WRKSRC}/src/build/slack.conf ${STAGEDIR}${PREFIX}/etc/slack.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/GPL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fixfiles-and-dirs.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/slack-intro ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
