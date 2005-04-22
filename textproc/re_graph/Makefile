# ex:ts=8
# Ports collection makefile for:	re_graph
# Date created:			Apr 22, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	re_graph
PORTVERSION=	0.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.oualline.com/sw/re/
DISTNAME=	${PORTNAME:S/_/-/}_${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Regular Expression Graphing Program

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GD/Arrow.pm:${PORTSDIR}/graphics/p5-GD-Arrow

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/re_graph

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/re_graph.pl ${PREFIX}/bin/re_graph
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/re_graph.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tut* ${DOCSDIR}
.endif

.include <bsd.port.mk>
