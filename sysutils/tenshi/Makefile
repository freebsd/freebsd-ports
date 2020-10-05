# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=	tenshi
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dev.inversepath.com/tenshi/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Log monitoring program, designed to watch multiple logs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/gtail:sysutils/coreutils \
		p5-IO-BufferedSelect>=0:devel/p5-IO-BufferedSelect

USES=		perl5
USE_PERL5=	build patch run
USE_RC_SUBR=	tenshi

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	PERL=${PERL}

PLIST_FILES=	bin/tenshi \
		etc/tenshi.conf.sample \
		share/man/man8/tenshi.8.gz

PORTDOCS=	Changelog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${PERL5} -pi.bak -e ' \
		s"/usr/bin/perl"${PERL}" if $$. == 1; \
		s"/etc/tenshi/tenshi\.conf"${PREFIX}/etc/tenshi.conf"; \
		s"/usr/bin/tail"${LOCALBASE}/bin/gtail"; \
		' ${WRKSRC}/tenshi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tenshi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tenshi.conf ${STAGEDIR}${PREFIX}/etc/tenshi.conf.sample
	${INSTALL_MAN} ${WRKSRC}/tenshi.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
