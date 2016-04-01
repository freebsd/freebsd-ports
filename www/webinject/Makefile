# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	webinject
PORTVERSION=	1.41
PORTREVISION=	1
CATEGORIES=	www perl5 devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20-%20Source%20Code%20%28with%20UNIX%20style%20line%20endings%29
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for automated testing of web applications

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-Error>=0:lang/p5-Error \
	        p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay

#.if !defined(WITHOUT_X11)
# some work to do here
#RUN_DEPENDS+=	p5-Tk>=0:x11-toolkits/p5-Tk
#.endif

USES=		perl5 shebangfix
SHEBANG_FILES=	webinject.pl
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/webinject.pl \
		${DATADIR:S,^${PREFIX}/,,}/config.xml \
		${DATADIR:S,^${PREFIX}/,,}/testcases.xml

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} *.xml ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} webinject.pl ${STAGEDIR}${PREFIX}/bin

PORTDOCS=	LICENSE README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
