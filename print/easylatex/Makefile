# New ports collection makefile for:	easylatex
# Date created:		2006-02-15
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	easylatex
PORTVERSION=	0.080
PORTREVISION=	0
CATEGORIES=	print textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Perl script which transforms "pseudo-LaTeX" into proper LaTeX

RUN_DEPENDS=	${SITE_PERL}/${SITE_ARCH}/Getopt/Declare.pm:${PORTSDIR}/devel/p5-Getopt-Declare

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/easylatex,${DATADIR},' \
		${WRKSRC}/${PORTNAME}.pl

do-install:
# script/data
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_SHARE} . ${DATADIR}
# docs, examples
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo.txt ${WRKSRC}/demo-no-graph.txt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
