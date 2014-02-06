# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmltv
PORTVERSION=	0.5.61
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	SF
PKGNAMEPREFIX=	p5-

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of programs to process TV (tvguide) listings in XML format

XMLTV_DEPENDS=	\
	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
	p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
	p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
	p5-PerlIO-gzip>=0:${PORTSDIR}/archivers/p5-PerlIO-gzip \
	p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
	p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
	p5-Tk-TableMatrix>=0:${PORTSDIR}/x11-toolkits/p5-Tk-TableMatrix \
	ja-p5-Text-Kakasi>=0:${PORTSDIR}/japanese/p5-Text-Kakasi \
	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
	p5-HTML-TableExtract>=0:${PORTSDIR}/www/p5-HTML-TableExtract \
	p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
	p5-Term-ProgressBar>=0:${PORTSDIR}/devel/p5-Term-ProgressBar \
	p5-Lingua-Preferred>=0:${PORTSDIR}/textproc/p5-Lingua-Preferred \
	p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String \
	p5-Unicode-UTF8simple>=0:${PORTSDIR}/converters/p5-Unicode-UTF8simple \
	p5-Lingua-EN-Numbers-Ordinate>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Numbers-Ordinate \
	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
	p5-HTTP-Cache-Transparent>=0:${PORTSDIR}/www/p5-HTTP-Cache-Transparent \
	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate
BUILD_DEPENDS=	${XMLTV_DEPENDS}
RUN_DEPENDS=	${XMLTV_DEPENDS}

USES=		perl5
USE_BZIP2=	yes
USE_PERL5=	configure

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

.ifdef(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-noportdocs-patch-Makefile.PL
.else
PORTDOCS=	COPYING \
		QuickStart \
		README \
		README.tv_check \
		README.win32 \
		tv_check_doc.html \
		tv_check_doc.jpg
.endif

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
	${MKDIR} ${STAGEDIR}${PREFIX}/${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/choose/tv_pick/tv_pick_cgi \
		${STAGEDIR}${PREFIX}/${CGIDIR}/tv_pick.cgi

.include <bsd.port.mk>
