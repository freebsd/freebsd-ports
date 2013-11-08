# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=		tenshi
PORTVERSION=		0.14
CATEGORIES=		sysutils
MASTER_SITES=		http://dev.inversepath.com/tenshi/

MAINTAINER=		jadawin@FreeBSD.org
COMMENT=		Tenshi is a log monitoring program, designed to watch multiple logs

RUN_DEPENDS=		${LOCALBASE}/bin/gtail:${PORTSDIR}/sysutils/coreutils \
			p5-IO-BufferedSelect>=0:${PORTSDIR}/devel/p5-IO-BufferedSelect

USES=			perl5
USE_PERL5=		run build patch
NO_BUILD=		yes
USE_RC_SUBR=		tenshi
SUB_LIST=		PERL=${PERL}

OPTIONS_DEFINE=		DOCS

PLIST_FILES=		bin/tenshi etc/tenshi.conf.sample man/man8/tenshi.8.gz

PORTDOCS=		README Changelog

.include <bsd.port.options.mk>

post-patch:
	@${PERL5} -pi.bak -e ' \
		s"/usr/bin/perl"${PERL}" if $$. == 1; \
		s"/etc/tenshi/tenshi\.conf"${STAGEDIR}${PREFIX}/etc/tenshi.conf"; \
		s"/usr/bin/tail"${LOCALBASE}/bin/gtail"; \
		' ${WRKSRC}/tenshi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tenshi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tenshi.conf ${STAGEDIR}${PREFIX}/etc/tenshi.conf.sample
	${INSTALL_MAN} ${WRKSRC}/tenshi.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
