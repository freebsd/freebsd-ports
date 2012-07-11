# New ports collection makefile for:	webinject
# Date created:				August 22nd 2006
# Whom:	      				Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	webinject
PORTVERSION=	1.41
PORTREVISION=	1
CATEGORIES=	www perl5 devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20-%20Source%20Code%20%28with%20UNIX%20style%20line%20endings%29
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for automated testing of web applications

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
	        p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay

.if !defined(WITHOUT_X11)
# some work to do here
#RUN_DEPENDS+=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk
.endif

USE_PERL5=	5.8.0+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/webinject.pl \
		${DATADIR:S,^${PREFIX}/,,}/config.xml \
		${DATADIR:S,^${PREFIX}/,,}/testcases.xml
PLIST_DIRS=	${DATADIR:S,^${PREFIX}/,,}

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} *.xml ${DATADIR}
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} webinject.pl ${PREFIX}/bin

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
