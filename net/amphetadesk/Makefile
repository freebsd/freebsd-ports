# New ports collection makefile for:	AmphetaDesk
# Date created:		Sun Oct  9 18:12:56 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amphetadesk
PORTVERSION=	0.93.1
CATEGORIES=	net perl5 www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-v${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	News, weblog, and RSS aggregator with a brain

RUN_DEPENDS=	\
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5_RUN=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

.ifndef(NOPORTDOCS)
PORTDOCS=	\
		*
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 -x -n 10 \
		${REINPLACE_CMD} -E \
		-e 's|([[:space:]]+)(AmphetaDesk)|\1AmphetaDesk::\2|g' \
		-e 's|([[:space:]]*)(Text::Template)|\1AmphetaDesk::\2|g' \
		-e 's|([[:space:]]*)(XML::Simple)|\1AmphetaDesk::\2|g'
	@${REINPLACE_CMD} -E \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/lib/AmphetaDesk/Settings.pm

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/AmphetaDesk.pl
	@${SED} \
		-e "s|%%PREFIX%%|${PREFIX}|" \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e "s|%%PERL%%|${PERL}|" \
		${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

do-install:
## create site_perl
# dirs
	@${MKDIR} ${SITE_PERL:S|${LOCALBASE}|${PREFIX}|}/AmphetaDesk
	@cd ${WRKSRC}/lib && \
		${FIND} * -type d ! -empty -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${MKDIR} ${SITE_PERL:S|${LOCALBASE}|${PREFIX}|}/AmphetaDesk/{}
# files
	@cd ${WRKSRC}/lib && \
		${FIND} * -type f -name "*pm" -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${INSTALL_DATA} {} ${SITE_PERL:S|${LOCALBASE}|${PREFIX}|}/AmphetaDesk/{}
# script
	@${INSTALL_DATA} ${WRKSRC}/AmphetaDesk.pl \
		${PREFIX}/bin/AmphetaDesk-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/bin/AmphetaDesk
## docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in html txt xml
	@${INSTALL_DATA} ${WRKSRC}/docs/*.${ext} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/images
.for ext in gif jpg
	@${INSTALL_DATA} ${WRKSRC}/docs/images/*.${ext} \
		${DOCSDIR}/images
.endfor
.endif
## lists
	@${MKDIR} ${DATADIR}/lists
	@${INSTALL_DATA} ${WRKSRC}/data/lists/services-channels-recent.xml \
		${DATADIR}/lists
## templates
# dirs
	@cd ${WRKSRC} && \
		${FIND} templates -type d ! -empty -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${MKDIR} ${DATADIR}/{}
# files
.for ext in gif html ico png pict
	@cd ${WRKSRC} && \
		${FIND} templates -type f -name "*.${ext}" -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${INSTALL_DATA} {} ${DATADIR}/{}
.endfor

.include <bsd.port.mk>
