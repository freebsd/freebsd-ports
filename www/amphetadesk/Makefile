# Ports collection Makefile for:	AmphetaDesk
# Date created:				8 April 2004
# Whom:					kstailey
#
# $FreeBSD$
#

PORTNAME=	amphetadesk
PORTVERSION=	0.93.1
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTNAME}-src-v${PORTVERSION}
DISTNAME=	${PORTNAME}-src-v${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	RSS client that serves HTTP to your local web browser

RUN_DEPENDS=	\
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template \
		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI

USE_PERL5=	yes
USE_RC_SUBR=	${PORTNAME}
NO_BUILD=	yes

# Add PERL substitution to SUB_LIST only if there is not already
# one listed
.if !defined(SUB_LIST) || ( defined(SUB_LIST) && !${SUB_LIST:MPERL} )
SUB_LIST+=	PERL="${PERL}"
.endif

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
