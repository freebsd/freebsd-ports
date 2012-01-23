# New ports collection makefile for:	hellanzb
# Date created:		Sat Sep 25 18:46:46 PDT 2004
# Whom:			Philip Jenvey <pjenvey@groovie.org>
#
# $FreeBSD$
# $Id: Makefile 828 2006-09-10 01:20:41Z pjenvey $
#

PORTNAME=	hellanzb
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.hellanzb.com/distfiles/

MAINTAINER=	pjenvey@groovie.org
COMMENT=	Nzb downloader and post processor

LICENSE=	BSD

RUN_DEPENDS=	par2:${PORTSDIR}/archivers/par2cmdline \
		flac:${PORTSDIR}/audio/flac \
		shorten:${PORTSDIR}/audio/shorten \
		${PYTHON_PKGNAMEPREFIX}yenc>=0:${PORTSDIR}/news/py-yenc \
		mac:${PORTSDIR}/audio/mac

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
USE_TWISTED_RUN=	web

.include <bsd.port.pre.mk>

# more fully-featured rar needs i386
.if ${ARCH} == "i386"
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.else
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGELOG CREDITS README
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/hellanzb.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_DATA} ${WRKSRC}/etc/hellanzb.conf.sample ${PREFIX}/etc/hellanzb.conf; \
	fi

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
