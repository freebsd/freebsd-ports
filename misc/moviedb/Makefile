# New ports collection makefile for:	moviedb
# Date created:				13 August 2000
# Whom:					Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	moviedb
PORTVERSION=	3.8
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.imdb.com/pub/interfaces/ \
		ftp://ftp.fu-berlin.de/pub/misc/movies/database/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.imdb.com/pub/interfaces/ \
		ftp://ftp.sunet.se/pub/tv+movies/imdb/
DISTFILES=	tools/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} ${IGNOREFILES}
DIST_SUBDIR=	moviedb
EXTRACT_ONLY=	tools/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	user@unknown.nu
COMMENT=	The Internet Movie Database package

IGNOREFILES=	actors.list.gz actresses.list.gz aka-names.list.gz \
	aka-titles.list.gz alternate-versions.list.gz biographies.list.gz \
	business.list.gz certificates.list.gz cinematographers.list.gz \
	color-info.list.gz complete-cast.list.gz complete-crew.list.gz \
	composers.list.gz costume-designers.list.gz countries.list.gz \
	crazy-credits.list.gz directors.list.gz distributors.list.gz editors.list.gz \
	genres.list.gz german-aka-titles.list.gz goofs.list.gz iso-aka-titles.list.gz \
	italian-aka-titles.list.gz keywords.list.gz language.list.gz \
	laserdisc.list.gz literature.list.gz locations.list.gz miscellaneous.list.gz \
	movie-links.list.gz movies.list.gz mpaa-ratings-reasons.list.gz plot.list.gz \
	producers.list.gz production-companies.list.gz production-designers.list.gz \
	quotes.list.gz ratings.list.gz release-dates.list.gz running-times.list.gz \
	sound-mix.list.gz soundtracks.list.gz special-effects-companies.list.gz \
	taglines.list.gz technical.list.gz trivia.list.gz writers.list.gz

ALL_TARGET=	compile
INSTALL_TARGET=	installbin databases compress installman
MAN1=		alist.1 lformat.1 lguide.1 lindex.1 list.1 listall.1 lseen.1 \
		ltrace.1 mkballot.1 title.1

NO_CDROM=	Cannot sell in any form
NO_PACKAGE=	Libraries cannot be distributed, and change every day anyway
RESTRICTED=	No commercial use

pre-fetch:
	@${ECHO}
	@${ECHO} "PLEASE NOTE! This is a large port; it requires between 300"
	@${ECHO} "and 400MB free to install. Kill it now if you don't have"
	@${ECHO} "the space."
	@${ECHO}

post-patch:
	cd $(DISTDIR)/$(DIST_SUBDIR);cp -v $(IGNOREFILES) $(WRKSRC)/lists/

pre-install:
	[ -d ${PREFIX}/lib/moviedb/ ] \
		|| ${MKDIR} ${PREFIX}/lib/moviedb
	${INSTALL_DATA} ${WRKSRC}/dbs/Makefile ${PREFIX}/lib/moviedb/
	[ -d ${PREFIX}/libexec/moviedb/ ] \
		|| ${MKDIR} ${PREFIX}/libexec/moviedb
	${INSTALL_DATA} ${WRKSRC}/etc/Makefile ${PREFIX}/libexec/moviedb/
.for SCRIPT in lfetch make-base recompress
	${INSTALL_SCRIPT} ${WRKSRC}/etc/${SCRIPT} ${PREFIX}/libexec/moviedb
.endfor

post-install:
.for STRIP in alist lformat lguide lindex list listall lseen ltrace mkballot \
template templist title
	${STRIP_CMD} ${PREFIX}/bin/${STRIP}
.endfor
	${STRIP_CMD} ${PREFIX}/libexec/moviedb/mkdb
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/moviedb
.for DOC in ADDS-GUIDE ChangeLog FAQ FUTURES INSTRUCTIONS manual.tex
	${INSTALL_DATA} ${WRKSRC}/docs/${DOC} ${PREFIX}/share/doc/moviedb
.endfor
.endif

.include <bsd.port.mk>
