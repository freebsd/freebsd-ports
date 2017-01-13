# Created by: Andreas Fehlner (fehlner@gmx.de)
# $FreeBSD$

PORTNAME=	usermatic
PORTVERSION=	0.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://btw23.de/johannes/usermatic/\
		http://home.arcor.de/fehlner/fbsd_ports/\
		http://home.arcor.de/teambushido/fbsd_ports/

MAINTAINER=	fehlner@gmx.de
COMMENT=	Scripts to automate the maintenance of accounts

RUN_DEPENDS=	${LOCALBASE}/sbin/userneu.pl:sysutils/userneu

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	digestion/digestion.pl hunter-seeker/hunter-seeker.pl \
		newusers/newusers.pl reaper/reaper.pl
USE_PERL5=	run
DOCS=		Artistic COPYING README CHANGES \
		doc/digestion.pl.pod doc/hunter-seeker.pl.pod \
		doc/reaper.pl.pod
EXAMPLES=	digestion/list_digested digestion/list_raw \
		newusers/sums_to_ignore
OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} digestion.pl.1 ${STAGEDIR}${MANPREFIX}/man/man1
	cd ${WRKSRC}/doc && ${INSTALL_MAN} hunter-seeker.pl.8 newusers.pl.8 reaper.pl.8 ${STAGEDIR}${MANPREFIX}/man/man8

	cd ${WRKSRC}/digestion && ${INSTALL_SCRIPT}  digestion.pl ${STAGEDIR}${PREFIX}/sbin
	cd ${WRKSRC}/hunter-seeker && ${INSTALL_SCRIPT} hunter-seeker.pl \
		${STAGEDIR}${PREFIX}/sbin
	cd ${WRKSRC}/reaper && ${INSTALL_SCRIPT} reaper.pl ${STAGEDIR}${PREFIX}/sbin
	cd ${WRKSRC}/newusers && ${INSTALL_SCRIPT} newusers.pl ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
