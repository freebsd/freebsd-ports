PORTNAME=	oksh
DISTVERSION=	7.0
PORTEPOCH=	1
CATEGORIES=	shells
MASTER_SITES=	https://github.com/ibara/oksh/releases/download/oksh-${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Portable OpenBSD Korn shell

LICENSE=	PD

FLAVORS=	dynamic static
FLAVOR?=	${FLAVORS:[1]}

static_PKGNAMESUFFIX=	-static
.if ${FLAVOR} == static
COMMENT+=		(rescue(8) version)
.endif

HAS_CONFIGURE=		yes
.if ${FLAVOR} == static
CONFIGURE_ARGS+=	--enable-static
PLIST=			/dev/null
PLIST_FILES=		"@shell /rescue/oksh"
.endif

OPTIONS_DEFINE=		CURSES
OPTIONS_DEFAULT=	CURSES

CURSES_DESC=	Use ncurses for screen clearing routines

CURSES_USES=			ncurses
CURSES_CONFIGURE_ENABLE=	curses

.if ${FLAVOR} == static
do-install:
	@${MKDIR} ${STAGEDIR}/rescue
	${INSTALL_PROGRAM} ${WRKSRC}/oksh ${STAGEDIR}/rescue
.endif

.include <bsd.port.mk>
