# Created by: lars.eggert@gmx.net
# $FreeBSD$

PORTNAME=	podcastamatic
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://kenwardtown.com/projects/podcastamatic/ \
		http://people.nokia.net/~lars/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Automates creation of webpage and RSS feed for a podcast

RUN_DEPENDS=	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-MP4-Info>=0:${PORTSDIR}/multimedia/p5-MP4-Info

USES=		perl5 zip
USE_PERL5=	run

NO_BUILD=	yes

NO_STAGE=	yes
do-patch:
	@${REINPLACE_CMD} -e "s|${PORTNAME}.conf|${PREFIX}/etc/${PORTNAME}.conf|"\
		 ${WRKSRC}/${PORTNAME}.pl
	@${REINPLACE_CMD} -e "s|../test/podcastamatic.log|/var/log/${PORTNAME}.log|"\
		${WRKSRC}/example_${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|/projects/podcastamatic|/podcast|"\
		${WRKSRC}/example_${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|style.css|${PREFIX}/share/${PORTNAME}/style.css|"\
		${WRKSRC}/example_${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|/testpodcast||" ${WRKSRC}/example_${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|/audio||" ${WRKSRC}/example_${PORTNAME}.conf
	@${REINPLACE_CMD} -e "s|[wW]:|${PREFIX}/www|" ${WRKSRC}/example_${PORTNAME}.conf

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/example_${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	test \! -f ${PREFIX}/etc/${PORTNAME}.conf && ${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf || true
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/style.css ${PREFIX}/share/${PORTNAME}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.html ${DOCSDIR}
.endif
	@${ECHO}
	@${ECHO} "Edit ${PREFIX}/etc/${PORTNAME}.conf"
	@${ECHO} "CSS in ${PREFIX}/share/${PORTNAME}/style.css"
	@${ECHO}

.include <bsd.port.mk>
