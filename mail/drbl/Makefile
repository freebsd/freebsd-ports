# New ports collection makefile for:	drbl
# Date created:				21 March 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	drbl
PORTVERSION=	2.2
CATEGORIES=	mail
MASTER_SITES=	http://www.agk.nnov.ru/drbl/prog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed Realtime Black List

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PERL5=	yes

post-patch:
	@${PERL} -pi.bak -e 's,./drblnode.conf,${PREFIX}/etc/drblnode.conf,g' ${WRKSRC}/*pl
	@${PERL} -pi.bak -e 's,(config.pl|drbllib.pl),${DATADIR}/\1,g' ${WRKSRC}/*pl
	@${PERL} -pi.bak -e 's,./header,${DATADIR}/header,g' ${WRKSRC}/drblnode.conf.sample
	@${PERL} -pi.bak -e 's, do_, ${PREFIX}/bin/do_,g' ${WRKSRC}/create_drbl.sh

do-install:
	@${MKDIR} ${DATADIR}
.for f in config.pl drbllib.pl header
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DATADIR}
.endfor
	@${MKDIR} ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/drblnode.conf.sample ${PREFIX}/etc
.if !exists(${PREFIX}/etc/drblnode.conf)
	${CP} ${PREFIX}/etc/drblnode.conf.sample ${PREFIX}/etc/drblnode.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.for f in create_drbl.sh do_drbl.pl do_info.pl do_vote.pl
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
