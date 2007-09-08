# New ports collection makefile for:	webinject
# Date created:				August 22nd 2006
# Whom:	      				Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	webinject
PORTVERSION=	1.41
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webinject
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A tool for automated testing of web applications

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/mach/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
	        ${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay

.if !defined(WITHOUT_X11)
# some work to do here
#RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
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
