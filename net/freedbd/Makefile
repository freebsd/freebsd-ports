# New ports collection makefile for:	freedbd
# Date created:				25 Aug 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	freedbd
PORTVERSION=	0.1
CATEGORIES=	net audio
MASTER_SITES=	http://rink.nu/downloads/projects/

MAINTAINER=	ed@fxq.nl
COMMENT=	A lightweight daemon for answering FreeDB queries

GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/freedbd bin/freedbd-txt2xml %%EXAMPLESDIR%%/sample_db.txt
PLIST_DIRS=	%%EXAMPLESDIR%%

OPTIONS=	XML "XML support" off

.include <bsd.port.pre.mk>

.if defined(WITH_XML)
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=--with-xml
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
PLIST_FILES+=	bin/freedbd-parse %%EXAMPLESDIR%%/sample_db.xml
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/txt2xml.pl ${PREFIX}/bin/freedbd-txt2xml
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/sample_db.txt ${EXAMPLESDIR}
.if defined(WITH_XML)
	${INSTALL_SCRIPT} ${WRKSRC}/tools/db_parse.pl ${PREFIX}/bin/freedbd-parse
	${INSTALL_DATA} ${WRKSRC}/examples/sample_db.xml ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
