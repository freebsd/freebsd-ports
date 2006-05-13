# New ports collection makefile for:	xslint
# Date created:			11 August 2001
# Whom:				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	xslint
PORTVERSION=	005
CATEGORIES=	textproc perl5
MASTER_SITES=	http://nwalsh.com/xml/xslint/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL(T) stylesheet checker

RUN_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM

USE_ZIP=	yes
USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-0.05
NO_BUILD=	yes

PLIST_FILES=	bin/xslint
PORTDOCS=	README xslint.html xslint.xml

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' ${WRKSRC}/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
	  ${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.mk>
