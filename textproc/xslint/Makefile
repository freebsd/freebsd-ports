# New ports collection makefile for:	xslint
# Date created:			11 August 2001
# Whom:				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	xslint
PORTVERSION=	005
CATEGORIES=	textproc perl5
MASTER_SITES=	http://nwalsh.com/xsl/xslint/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	XSL(T) stylesheet checker

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM

USE_PERL5=	yes
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

post-patch:
	${PERL5} -pi -e 's,/usr/local/bin/perl5,${PERL},' ${WRKSRC}/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xslint.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xslint.xml ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
