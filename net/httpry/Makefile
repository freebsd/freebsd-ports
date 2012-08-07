# New ports collection makefile for:   httpry
# Date created:        12 June 2008
# Whom:                Wesley Shields <wxs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httpry
PORTVERSION=	0.1.7
CATEGORIES=	net
MASTER_SITES=	http://dumpsterventures.com/jason/httpry/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Packet sniffer designed for displaying and logging HTTP traffic

MAN1=		httpry.1

USE_RC_SUBR=	httpry
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	EXTRASCRIPTS
EXTRASCRIPTS_DESC=	Install additional scripts

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXTRASCRIPTS}
PLIST_SUB=	EXTRASCRIPTS=""
USE_PERL5_RUN=	yes
RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
. if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
. endif
.else
PLIST_SUB=	EXTRASCRIPTS="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXTRASCRIPTS}
	${MKDIR} ${PREFIX}/bin/httpry-scripts
	(cd ${WRKSRC}/scripts/ && \
		${COPYTREE_BIN} \* ${PREFIX}/bin/httpry-scripts "! -name *.bak")
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/perl-tools ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/format-string ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
