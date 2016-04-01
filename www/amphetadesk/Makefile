# Created by: kstailey
# $FreeBSD$

PORTNAME=	amphetadesk
PORTVERSION=	0.93.1
PORTREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTNAME}-src-v${PORTVERSION}
DISTNAME=	${PORTNAME}-src-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RSS client that serves HTTP to your local web browser

LICENSE=	EULA
LICENSE_NAME=	The Clarified Artistic License
LICENSE_FILE=	${WRKSRC}/docs/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	\
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-HTML-Tagset>=0:www/p5-HTML-Tagset \
		p5-libwww>=0:www/p5-libwww \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Text-Template>=0:textproc/p5-Text-Template \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}
NO_BUILD=	yes

# Add PERL substitution to SUB_LIST only if there is not already
# one listed
.if !defined(SUB_LIST) || ( defined(SUB_LIST) && !${SUB_LIST:MPERL} )
SUB_LIST+=	PERL="${PERL}"
.endif

PORTDOCS=	*

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 -x -n 10 \
		${REINPLACE_CMD} -E \
		-e 's|([[:space:]]+)(AmphetaDesk)|\1AmphetaDesk::\2|g' \
		-e 's|([[:space:]]*)(Text::Template)|\1AmphetaDesk::\2|g' \
		-e 's|([[:space:]]*)(XML::Simple)|\1AmphetaDesk::\2|g' \
		-e 's|^.*use[[:space:]]*FindBin.*$$||' \
		-e "s|\([\$$]Bin|\(\$$ENV{'DIRNAME'}|g"
	@${REINPLACE_CMD} -E \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|' \
		${WRKSRC}/lib/AmphetaDesk/Settings.pm

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|^.*/usr/bin/perl.*$$||' \
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
	@${MKDIR} ${SITE_PERL:S|${LOCALBASE}|${STAGEDIR}${PREFIX}|}/AmphetaDesk
	@(cd ${WRKSRC}/lib && \
		${FIND} * -type d ! -empty -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${MKDIR} ${SITE_PERL:S|${LOCALBASE}|${STAGEDIR}${PREFIX}|}/AmphetaDesk/{})
# files
	(cd ${WRKSRC}/lib && \
		${FIND} * -type f -name "*pm" -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${INSTALL_DATA} {} ${SITE_PERL:S|${LOCALBASE}|${STAGEDIR}${PREFIX}|}/AmphetaDesk/{})
# script
	${INSTALL_DATA} ${WRKSRC}/AmphetaDesk.pl \
		${STAGEDIR}${PREFIX}/bin/AmphetaDesk-real
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${STAGEDIR}${PREFIX}/bin/AmphetaDesk
## docs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for ext in html txt xml
	${INSTALL_DATA} ${WRKSRC}/docs/*.${ext} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
.for ext in gif jpg
	${INSTALL_DATA} ${WRKSRC}/docs/images/*.${ext} \
		${STAGEDIR}${DOCSDIR}/images
.endfor
## lists
	@${MKDIR} ${STAGEDIR}${DATADIR}/lists
	${INSTALL_DATA} ${WRKSRC}/data/lists/services-channels-recent.xml \
		${STAGEDIR}${DATADIR}/lists
## templates
# dirs
	(cd ${WRKSRC} && \
		${FIND} templates -type d ! -empty -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${MKDIR} ${STAGEDIR}${DATADIR}/{})
# files
.for ext in gif html ico png pict
	(cd ${WRKSRC} && \
		${FIND} templates -type f -name "*.${ext}" -print0 | \
		${XARGS} -0 -x -n 10 -I {} \
		${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{})
.endfor

.include <bsd.port.post.mk>
