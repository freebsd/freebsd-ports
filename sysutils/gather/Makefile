# New ports collection makefile for:	gather
# Date created:				14 February 2010
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gather
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Utility to store and display system statistics

LICENSE=	BSD

PROJECTHOST=	gatherit

USES=		perl5

CONFLICTS_INSTALL=	harvest-[0-9]*

DATADIR=	/var/db/gather
MAKE_ENV+=	CONFDIR=${PREFIX}/etc/gather DATADIR=${DATADIR}

SUB_FILES=	pkg-message

MAN1=		gather.1

.if !defined(NOPORTDOCS)
PORTDOCS=	Changelog README
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/gather ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/gather.1 ${PREFIX}/man/man1
.if !exists(${PREFIX}/etc/gather)
	@${MKDIR} ${PREFIX}/etc/gather
.endif
	@${INSTALL_DATA} ${WRKSRC}/gather.cfg ${PREFIX}/etc/gather/gather.cfg.sample
.if !exists(${CONFDIR}/gather.cfg)
	@${INSTALL_DATA} ${WRKSRC}/gather.cfg ${PREFIX}/etc/gather/gather.cfg
.endif
	@${INSTALL_DATA} ${WRKSRC}/examples/gather.map.freebsd ${PREFIX}/etc/gather/gather.map.sample
.if !exists(${PREFIX}/etc/gather/gather.cfg)
	@${INSTALL_DATA} ${WRKSRC}/examples/gather.map.freebsd ${PREFIX}/etc/gather/gather.map
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
