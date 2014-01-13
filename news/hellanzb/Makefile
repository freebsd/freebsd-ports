# Created by: Philip Jenvey <pjenvey@groovie.org>
# $FreeBSD$

PORTNAME=	hellanzb
PORTVERSION=	0.13
PORTREVISION=	2
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

USE_PYTHON=	2
USE_PYDISTUTILS=yes
USES=		twisted:run,web
PORTDOCS=	CHANGELOG CREDITS README

NO_STAGE=	yes
.include <bsd.port.options.mk>

# more fully-featured rar needs i386
.if ${ARCH} == "i386"
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.else
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/hellanzb.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_DATA} ${WRKSRC}/etc/hellanzb.conf.sample ${PREFIX}/etc/hellanzb.conf; \
	fi

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
