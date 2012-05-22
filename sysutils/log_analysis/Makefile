# New ports collection makefile for:	log_analysis
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	log_analysis
PORTVERSION=	0.46
CATEGORIES=	sysutils
MASTER_SITES=	http://userpages.umbc.edu/~mabzug1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility that extracts a summary of useful data from logs

LICENSE=	GPLv3

OPTIONS=	TK "Enable Tcl/Tk GUI support" off

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"

MAN1=		log_analysis.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/log_analysis \
		%%DATADIR%%/AUTHORS \
		%%DATADIR%%/Tk/resizebutton.pm
PLIST_DIRS=	%%DATADIR%%/Tk \
		%%DATADIR%%

.include <bsd.port.options.mk>

.if defined(WITH_TK)
RUN_DEPENDS+=	p5-Tk>0:${PORTSDIR}/x11-toolkits/p5-Tk
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Tutorial ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample-* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
