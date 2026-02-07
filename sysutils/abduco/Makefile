PORTNAME=	abduco
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.brain-dump.org/projects/abduco/

MAINTAINER=	swdragonmaus@gmail.com
COMMENT=	Session management in a clean and simple way
WWW=		http://www.brain-dump.org/projects/abduco/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	CPPFLAGS="${CPPFLAGS}" STRIP="${STRIP_CMD}"
PLIST_FILES=	bin/abduco \
		share/man/man1/abduco.1.gz

MAKE_JOBS_UNSAFE=	yes

pre-everything::
	@${ECHO_MSG} "You can build abduco with your own config.h using the ABDUCO_CONF knob:"
	@${ECHO_MSG} "make ABDUCO_CONF=/path/to/abduco/config.h install clean"

post-extract:
	@if [ -e "${ABDUCO_CONF}" ]; then \
		${ECHO_MSG} "Creating symlink: config.h -> ${ABDUCO_CONF}"; \
		${LN} -fs "${ABDUCO_CONF}" ${WRKSRC}/config.h; \
	fi

.include <bsd.port.mk>
