PORTNAME=	apachetop
DISTVERSION=	0.23.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/tessus/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	Apache realtime log stats
WWW=		https://github.com/tessus/apachetop

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe ncurses readline

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ENV+=	NCURSES_CFLAGS="-I${NCURSESINC}" NCURSES_LIBS="-lncursesw"

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	ADNS FAM PCRE2

ADNS_DESC=	Asynchronous-capable DNS support
ADNS_LIB_DEPENDS=	libadns.so:dns/adns
ADNS_CONFIGURE_WITH=	adns=${LOCALBASE}

FAM_LIB_DEPENDS=	libfam.so:devel/fam
FAM_CONFIGURE_WITH=	fam=${LOCALBASE}

PCRE2_DESC=	Use Perl Compatible Regular Expressions (v2)
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_WITH=	pcre2=${LOCALBASE}

.include <bsd.port.mk>
