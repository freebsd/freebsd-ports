# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	cone
PORTVERSION=	0.94
CATEGORIES=	mail
# This is for beta versions, leave it in please:
#MASTER_SITES=	http://www.courier-mta.org/beta/${PORTNAME}/ \
#		http://www.lerctr.org/~ler/
# This is for release versions, leave it in please:
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console based mail client with POP3/IMAP/SMAP support

LICENSE=	GPLv3

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libcourier-unicode.so:devel/courier-unicode
BUILD_DEPENDS=	gpgv:security/gnupg1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		fam gettext gmake iconv ncurses perl5 shebangfix tar:bzip2
USE_GNOME=	libxml2

SHEBANG_FILES=	sysconftool

CPPFLAGS+=	-I${LOCALBASE}/include \
		-D_XOPEN_SOURCE_EXTENDED
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-certdb=${PREFIX}/share/cone/rootcerts --exec-prefix=${PREFIX}
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/leaf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mailtool
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/cone
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${STAGEDIR}${PREFIX}/sbin/cone-sysconftool
	${RM} ${STAGEDIR}${PREFIX}/share/cone/rootcerts/.0
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
