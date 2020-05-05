# $FreeBSD$

PORTNAME=	mmh
PORTVERSION=	0.4
CATEGORIES=	mail
MASTER_SITES=	http://marmaro.de/prog/mmh/files/

MAINTAINER=	satanist+freebsd@bureaucracy.de
COMMENT=	CLI mail user agent, fork from nmh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE=		iconv ncurses
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec/mmh \
				--sysconfdir=${ETCDIR} \
				--bindir=${PREFIX}/bin \
				--mandir=${PREFIX}/man \
				--docdir=${DOCSDIR} \

OPTIONS_SINGLE=	LOCKING
OPTIONS_SINGLE_LOCKING=	DOT FCNTL FLOCK LOCKF

DOT_DESC=		Dot file locking
DOT_CONFIGURE_ON=	--with-locking=dot
FCNTL_DESC=		fcntl() file locking
FCNTL_CONFIGURE_ON=	--with-locking=fcntl
FLOCK_DESC=		flock() file locking
FLOCK_CONFIGURE_ON=	--with-locking=flock
LOCKF_DESC=		lockf file locking
LOCKF_CONFIGURE_ON=	--with-locking=lockf

OPTIONS_DEFAULT=	FLOCK

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
LDFLAGS+=		-g
DEBUG_FLAGS+=		-O0 -Wall -Wextra -g
.endif

CONFLICTS=		ja-mh-[0-9]* nmh-[0-9]* p5-Dist-Joseki-*

post-install:
	@${FIND} ${STAGEDIR}${ETCDIR} -type f -exec ${MV} {} {}.sample \;

.include <bsd.port.mk>
