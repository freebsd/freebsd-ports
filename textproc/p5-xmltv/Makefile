# New ports collection makefile for:	xmltv
# Date created:		Mon Nov 4 02:56:34 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmltv
PORTVERSION=	0.5.3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmltv
PKGNAMEPREFIX=	p5-

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS= \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Tk/TableMatrix.pm:${PORTSDIR}/x11-toolkits/p5-Tk-TableMatrix
BUILD_DEPENDS+=	 \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Lingua/Preferred.pm:${PORTSDIR}/textproc/p5-Lingua-Preferred \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Memoize.pm:${PORTSDIR}/devel/p5-Memoize \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Lingua/EN/Numbers/Ordinate.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers-Ordinate \
	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/CharName.pm:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS=	${BUILD_DEPENDS}

IS_INTERACTIVE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
PERL_CONFIGURE=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=	tv_cat.1 tv_extractinfo_en.1 tv_grab_de.1 tv_grab_na.1 \
	tv_grab_sn.1 tv_grab_uk.1 tv_grab_uk_rt.1 tv_grep.1 tv_sort.1 \
	tv_to_latex.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	XMLTV.3

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
PLIST_SUB+=      CGIDIR="${CGIDIR}"

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|'
	@${FIND} ${WRKSRC} -type f \
		-name "*.bak" | \
		${XARGS} -n 10 ${RM}

pre-configure:
	@${ECHO_MSG}
	@${ECHO_MSG} '====> Please answer yes to all configure questions'
	@${ECHO_MSG} '====> The port is assuming that you have answered yes to all of them'
	@${ECHO_MSG}

post-install:
	@${MKDIR} ${PREFIX}/${CGIDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/choose/tv_pick/tv_pick_cgi ${PREFIX}/${CGIDIR}/tv_pick.cgi
.if defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "@unexec rmdir -p %D/${CGIDIR} 2>/dev/null || true" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
