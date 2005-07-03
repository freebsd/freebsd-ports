# New ports collection makefile for:	hellanzb
# Date created:		Sat Sep 25 18:46:46 PDT 2004
# Whom:			Philip Jenveey <pjenvey@groovie.org>
#
# $FreeBSD$
# $Id: Makefile 362 2005-06-30 22:41:56Z pjenvey $
#

PORTNAME=	hellanzb
PORTVERSION=	0.6
CATEGORIES=	news
MASTER_SITES=	http://www.hellanzb.com/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	pjenvey@groovie.org
COMMENT=	Nzb downloader and post processor

RUN_DEPENDS=	par2:${PORTSDIR}/archivers/par2cmdline \
		flac:${PORTSDIR}/audio/flac \
		shorten:${PORTSDIR}/audio/shorten \
		${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_SITELIBDIR}/twisted/web:${PORTSDIR}/www/py-twistedWeb

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

# monkey audio (mac) needs FreeBSD 5
.if ${OSVERSION} >= 500000
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif

# more fully-featured rar needs at least 5.3
.if ${ARCH} == "i386" && ${OSVERSION} >= 503000
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.else
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.ifndef(NOPORTDOCS)
PORTDOCS=	CHANGELOG CREDITS README LICENSE
.endif

post-install:

	@if [ ! -f ${PREFIX}/etc/hellanzb.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_DATA} ${WRKSRC}/etc/hellanzb.conf.sample ${PREFIX}/etc/hellanzb.conf; \
	fi

.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
