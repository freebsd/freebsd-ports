PORTNAME=	dvtm
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.brain-dump.org/projects/dvtm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiling window management for the console
WWW=		https://www.brain-dump.org/projects/dvtm/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses
PLIST_FILES=	bin/dvtm bin/dvtm-status \
		share/man/man1/dvtm.1.gz

MAKE_JOBS_UNSAFE=	yes

pre-everything::
	@${ECHO_MSG} "You can build dvtm with your own config.h using the DVTM_CONF knob:"
	@${ECHO_MSG} "make DVTM_CONF=/path/to/dvtm/config.h install clean"

post-extract:
.if defined(DVTM_CONF)
	@${ECHO_MSG} "creating config.h from ${DVTM_CONF}"
	@${CP} ${DVTM_CONF} ${WRKSRC}/config.h
.endif

.include <bsd.port.mk>
