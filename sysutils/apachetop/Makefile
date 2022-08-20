PORTNAME=	apachetop
DISTVERSION=	0.19.7
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tessus/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	Apache realtime log stats

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe ncurses readline

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	NCURSES_CFLAGS="-I${NCURSESINC}" NCURSES_LIBS="-lncursesw"

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	ADNS FAM PCRE

ADNS_DESC=	Asynchronous-capable DNS support
ADNS_LIB_DEPENDS=	libadns.so:dns/adns
ADNS_CONFIGURE_WITH=	adns=${LOCALBASE}

FAM_LIB_DEPENDS=	libfam.so:devel/fam
FAM_CONFIGURE_WITH=	fam=${LOCALBASE}

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre=${LOCALBASE}

.include <bsd.port.mk>
