# New ports collection makefile for:	tenshi
# Date created:				21 Jul 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		tenshi
PORTVERSION=		0.3.1
CATEGORIES=		sysutils
MASTER_SITES=		http://dev.gentoo.org/~lcars/%SUBDIR%/
MASTER_SITE_SUBDIR=	tenshi

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Tenshi is a log monitoring program, designed to watch multiple logs

RUN_DEPENDS=		${LOCALBASE}/bin/gtail:${PORTSDIR}/sysutils/coreutils

MAN8=			tenshi.8

USE_PERL5=		yes
NO_BUILD=		yes
USE_RC_SUBR=		yes

SED_SCRIPT=		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
			-e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%PERL%%,${PERL},g'

PORTDOCS=		README Changelog

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=			requires are least Perl 5.6
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=		${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
.endif

post-patch:
	@${PERL5} -pi.bak -e ' \
		s"/usr/bin/perl"${PERL}" if $$. == 1; \
		s"/etc/tenshi/tenshi\.conf"${PREFIX}/etc/tenshi.conf"; \
		s"/usr/bin/tail"${LOCALBASE}/bin/gtail"; \
		' ${WRKSRC}/tenshi

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tenshi ${DESTDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/tenshi.conf ${DESTDIR}${PREFIX}/etc/tenshi.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/tenshi.8 ${DESTDIR}${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for doc in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$doc ${DESTDIR}${DOCSDIR}; \
	done
.endif

post-install:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/tenshi.sh >${WRKDIR}/tenshi.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/tenshi.sh ${PREFIX}/etc/rc.d

.include <bsd.port.post.mk>
