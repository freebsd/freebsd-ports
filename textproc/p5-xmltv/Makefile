# New ports collection makefile for:	xmltv
# Date created:		Mon Nov 4 02:56:34 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmltv
PORTVERSION=	0.5.21
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmltv
PKGNAMEPREFIX=	p5-

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Set of programs to process TV (tvguide) listings in XML format

BUILD_DEPENDS=	\
	${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
	${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
	${SITE_PERL}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize \
	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${SITE_PERL}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
	${SITE_PERL}/HTML/Tree.pm:${PORTSDIR}/www/p5-HTML-Tree \
	${SITE_PERL}/${PERL_ARCH}/Tk/TableMatrix.pm:${PORTSDIR}/x11-toolkits/p5-Tk-TableMatrix \
	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
	${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
	${SITE_PERL}/Term/ProgressBar.pm:${PORTSDIR}/devel/p5-Term-ProgressBar \
	${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
	${SITE_PERL}/Lingua/Preferred.pm:${PORTSDIR}/textproc/p5-Lingua-Preferred \
	${SITE_PERL}/Lingua/EN/Numbers/Ordinate.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers-Ordinate \
	${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
PERL_CONFIGURE=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
IGNORE=	"perl 5.6 or higher is required to build this port"
.endif

.if ${OSVERSION} >= 500000
MAN1PREFIX=	${PREFIX}/share
.else
# override bsd.port.mk setting for perl ports
MAN3PREFIX=	${MANPREFIX}
.endif

MAN1=	tv_cat.1 tv_check.1 tv_extractinfo_en.1 tv_grab_dk.1 \
	tv_grab_es.1 tv_grab_fi.1 tv_grab_hu.1 tv_grab_it.1 \
	tv_grab_na.1 tv_grab_nl.1 tv_grab_nl_wolf.1 tv_grab_nz.1 \
	tv_grab_sn.1 tv_grab_uk.1 tv_grab_uk_rt.1 tv_grep.1 \
	tv_imdb.1 tv_remove_some_overlapping.1 tv_sort.1 tv_split.1 \
	tv_to_latex.1 tv_to_text.1
MAN3=	XMLTV.3 XMLTV::Grab_XML.3 XMLTV::Gunzip.3 XMLTV::Summarize.3

# idea taken from devel/cvsweb port
# Specify these directories in relative paths to ${PREFIX}.
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons
.else
CGIDIR?=	www/cgi-bin
ICONSDIR?=	www/icons
.endif
#
PLIST_SUB+=	CGIDIR="${CGIDIR}"

post-patch:
# fix man install location
	@${REINPLACE_CMD} -e \
		's|share/man|man|' \
		${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|'
	@${FIND} ${WRKSRC} -type f \
		-name "*.bak" | \
		${XARGS} -n 10 ${RM}

post-install:
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/choose/tv_pick/tv_pick_cgi ${PREFIX}/${CGIDIR}/tv_pick.cgi
.if defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "@unexec ${RMDIR} -p %D/${CGIDIR} 2>/dev/null || true" >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
