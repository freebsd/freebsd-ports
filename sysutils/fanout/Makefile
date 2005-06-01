# New ports collection makefile for:	fanout
# Date created:				20.01.2005
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	fanout
PORTVERSION=	0.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.stearns.org/fanout/ \
		ftp://ftp.bascom.com/pub/wstearns/fanout/ \
		http://www.linuxgrill.com/anonymous/mirrors/wstearns/fanout/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Tool to run commands on multiple machines

USE_PERL5_RUN=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
PLIST_FILES=	bin/fanout bin/fanterm bin/fanmux
.if !defined(NOPORTDOCS)
PORTDOCS=	README index.html
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/fanterm
	@${REINPLACE_CMD} -e 's,%%PERL%%,${PERL},g' \
		${WRKSRC}/fanmux

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fanout ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/fanterm ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/fanmux ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
