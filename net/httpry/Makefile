# $FreeBSD$

PORTNAME=	httpry
PORTVERSION=	0.1.7
CATEGORIES=	net
MASTER_SITES=	http://dumpsterventures.com/jason/httpry/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Packet sniffer designed for displaying and logging HTTP traffic

MAN1=		httpry.1

USE_RC_SUBR=	httpry

OPTIONS_DEFINE=	EXTRASCRIPTS
EXTRASCRIPTS_DESC=	Install additional scripts

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXTRASCRIPTS}
PLIST_SUB=	EXTRASCRIPTS=""
USES+=		perl5
USE_PERL5=	run
RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
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
