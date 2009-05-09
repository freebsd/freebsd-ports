# New ports collection makefile for:   httpry
# Date created:        12 June 2008
# Whom:                Wesley Shields <wxs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httpry
PORTVERSION=	0.1.3
CATEGORIES=	net
MASTER_SITES=	http://dumpsterventures.com/jason/httpry/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Packet sniffer designed for displaying and logging HTTP traffic

MAN1=		httpry.1

USE_RC_SUBR=	httpry
MAKE_JOBS_SAFE=	yes

OPTIONS=	EXTRASCRIPTS "Install additional scripts" Off

.include <bsd.port.pre.mk>

.if defined(WITH_EXTRASCRIPTS)
PLIST_SUB=	EXTRASCRIPTS=""
USE_PERL5_RUN=	yes
RUN_DEPENDS=	${SITE_PERL}/IO/Compress/Gzip.pm:${PORTSDIR}/archivers/p5-IO-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.else
PLIST_SUB=	EXTRASCRIPTS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's#^(\/etc.*)#${PREFIX}\1#' ${WRKSRC}/scripts/process_logs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if defined(WITH_EXTRASCRIPTS)
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
