# New ports collection makefile for:    aguri
# Date created:                        	27 February 2003
# Whom: 				Yann Berthier <yb@sainte-barbe.org>
#
# $FreeBSD$
#

PORTNAME=	aguri
PORTVERSION=	0.5
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	yb@sainte-barbe.org
COMMENT=	"An Aggregation-based Traffic Profiler"

USE_XLIB=	yes

MAN1=		aguri.1

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILES in INSTALL README
	@${INSTALL_DATA} ${WRKSRC}/${FILES} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/scripts/README ${DATADIR}
.for SCRIPTS in agurify.pl density.pl makeplot.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/${SCRIPTS} \
	${DATADIR}
.endfor

.include <bsd.port.mk>
