# New ports collection makefile for:	usermatic
# Date created:		10 Januar 2004
# Whom:			Andreas Fehlner (fehlner@gmx.de)
#
# $FreeBSD$
#

PORTNAME=	usermatic
PORTVERSION=	0.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://btmdx8.mat.uni-bayreuth.de/~johannes/usermatic/\
		http://home.arcor.de/fehlner/inhalt/download/\
		http://home.arcor.de/teambushido/

MAINTAINER=	fehlner@gmx.de
COMMENT=	Scripts to automate the maintenance of accounts

NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN1=	digestion.pl.1
MAN8=	hunter-seeker.pl.8 newusers.pl.8 reaper.pl.8

DOCS=		Artistic COPYING README CHANGES \
		doc/digestion.pl.pod doc/hunter-seeker.pl.pod \
		doc/reaper.pl.pod
EXAMPLES=	digestion/list_digested digestion/list_raw \
		newusers/sums_to_ignore

RUN_DEPENDS+=	${PREFIX}/sbin/userneu.pl:${PORTSDIR}/sysutils/userneu

do-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN8} ${MANPREFIX}/man/man8

	cd ${WRKSRC}/digestion && ${INSTALL_SCRIPT}  digestion.pl ${PREFIX}/sbin
	cd ${WRKSRC}/hunter-seeker && ${INSTALL_SCRIPT} hunter-seeker.pl \
		${PREFIX}/sbin
	cd ${WRKSRC}/reaper && ${INSTALL_SCRIPT} reaper.pl ${PREFIX}/sbin
	cd ${WRKSRC}/newusers && ${INSTALL_SCRIPT} newusers.pl ${PREFIX}/sbin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
