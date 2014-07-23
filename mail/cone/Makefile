# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	cone
PORTVERSION=	0.90
PORTREVISION=	4
CATEGORIES=	mail
# This is for beta versions, leave it in please:
#MASTER_SITES=	http://www.courier-mta.org/beta/${PORTNAME}/ \
#		http://www.lerctr.org/~ler/
# This is for release versions, leave it in please:
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	uffe@uffe.org
COMMENT=	Console based mail client with POP3/IMAP/SMAP support

LICENSE=	GPLv3

LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell
BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fam gettext gmake iconv ncurses perl5 shebangfix tar:bzip2
USE_GNOME=	libxml2

SHEBANG_FILES=	sysconftool

CPPFLAGS+=	-I${LOCALBASE}/include \
		-D_XOPEN_SOURCE_EXTENDED \
		-I${WRKDIR} -D_XOPEN_SOURCE_EXTENDED
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	-C --without-db --with-certdb=${PREFIX}/share/cone/rootcerts --exec-prefix=${PREFIX}
CONFIGURE_ENV=	REHASH="${PERL} ${SCRIPTDIR}/c_rehash"

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-extract:
		@${MKDIR} ${WRKDIR}/ncursesw
		${LN} -s ${LOCALBASE}/include/ncurses/ncurses.h ${WRKDIR}/ncursesw/curses.h

post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${STAGEDIR}${PREFIX}/sbin/cone-sysconftool
		${RM} -f ${STAGEDIR}${PREFIX}/share/cone/rootcerts/.0
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
