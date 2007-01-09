# New ports collection makefile for:	maketeidtd
# Date created:				18 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	maketeidtd
PORTVERSION=	20020414 # Cannot find a "real" version number
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Software/maketeidtd/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate customized TEI-DTDs

RUN_DEPENDS=	carthage:${PORTSDIR}/textproc/carthage \
		${LOCALBASE}/share/sgml/tei/p4/tei2.dtd:${PORTSDIR}/textproc/tei-p4

USE_PERL5=	yes
USE_ZIP=	yes
NO_BUILD=	yes

post-patch:
	@${MV} ${WRKSRC}/maketeidtd ${WRKSRC}/maketeidtd.tmp
	@${SED} -e 's;#!/usr/bin/perl;#!${PERL};' \
		 -e 's;../../P4X/DTD;${PREFIX}/share/sgml/tei/p4;' \
		${WRKSRC}/maketeidtd.tmp > ${WRKSRC}/maketeidtd
	@${RM} ${WRKSRC}/maketeidtd.tmp

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/maketeidtd ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/maketeidtd
	@${MKDIR} ${PREFIX}/share/examples/maketeidtd
	@${INSTALL_MAN} ${WRKSRC}/index.html ${PREFIX}/share/doc/maketeidtd
	@${INSTALL_MAN} ${WRKSRC}/index.xml ${PREFIX}/share/doc/maketeidtd
	@${INSTALL_MAN} ${WRKSRC}/index.xsl ${PREFIX}/share/doc/maketeidtd
	@${INSTALL_MAN} ${WRKSRC}/examples/* ${PREFIX}/share/examples/maketeidtd
.endif

.include <bsd.port.mk>
