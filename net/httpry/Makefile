# $FreeBSD$

PORTNAME=	httpry
PORTVERSION=	0.1.7
CATEGORIES=	net
MASTER_SITES=	http://dumpsterventures.com/jason/httpry/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet sniffer designed for displaying and logging HTTP traffic

USE_RC_SUBR=	httpry

OPTIONS_DEFINE=	EXTRASCRIPTS DOCS
EXTRASCRIPTS_DESC=	Install additional scripts

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXTRASCRIPTS}
PLIST_SUB+=	EXTRASCRIPTS=""
USES+=		perl5
USE_PERL5=	run
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI
.else
PLIST_SUB+=	EXTRASCRIPTS="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXTRASCRIPTS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/httpry-scripts
	(cd ${WRKSRC}/scripts/ && \
		${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/bin/httpry-scripts "! -name *.bak")
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/perl-tools ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/format-string ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
