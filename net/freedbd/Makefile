# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	freedbd
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net audio
MASTER_SITES=	http://rink.nu/downloads/projects/

MAINTAINER=	rink@FreeBSD.org
COMMENT=	A lightweight daemon for answering FreeDB queries

USES=		perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes
WANT_GNOME=	yes

PLIST_FILES=	bin/freedbd bin/freedbd-txt2xml %%EXAMPLESDIR%%/sample_db.txt
PLIST_DIRS=	%%EXAMPLESDIR%%

OPTIONS_DEFINE=	XML

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MXML}
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=--with-xml
RUN_DEPENDS+=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
PLIST_FILES+=	bin/freedbd-parse %%EXAMPLESDIR%%/sample_db.xml
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/txt2xml.pl ${PREFIX}/bin/freedbd-txt2xml
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/sample_db.txt ${EXAMPLESDIR}
.if ${PORT_OPTIONS:MXML}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/db_parse.pl ${PREFIX}/bin/freedbd-parse
	${INSTALL_DATA} ${WRKSRC}/examples/sample_db.xml ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
