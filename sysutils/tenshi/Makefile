# New ports collection makefile for:	tenshi
# Date created:				21 Jul 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		tenshi
PORTVERSION=		0.12
CATEGORIES=		sysutils
MASTER_SITES=		http://dev.inversepath.com/tenshi/

MAINTAINER=		jadawin@FreeBSD.org
COMMENT=		Tenshi is a log monitoring program, designed to watch multiple logs

RUN_DEPENDS=		${LOCALBASE}/bin/gtail:${PORTSDIR}/sysutils/coreutils \
			p5-IO-BufferedSelect>=0:${PORTSDIR}/devel/p5-IO-BufferedSelect

MAN8=			tenshi.8

USE_PERL5=		yes
NO_BUILD=		yes
USE_RC_SUBR=		tenshi
SUB_LIST=		PERL=${PERL}

PLIST_FILES=		bin/tenshi etc/tenshi.conf.sample
MAN8=			tenshi.8

PORTDOCS=		README Changelog

post-patch:
	@${PERL5} -pi.bak -e ' \
		s"/usr/bin/perl"${PERL}" if $$. == 1; \
		s"/etc/tenshi/tenshi\.conf"${PREFIX}/etc/tenshi.conf"; \
		s"/usr/bin/tail"${LOCALBASE}/bin/gtail"; \
		' ${WRKSRC}/tenshi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tenshi ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tenshi.conf ${PREFIX}/etc/tenshi.conf.sample
	${INSTALL_MAN} ${WRKSRC}/tenshi.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
