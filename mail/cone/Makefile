PORTNAME=	cone
DISTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	mail
# This is for beta versions, leave it in please:
#MASTER_SITES=	http://www.courier-mta.org/beta/${PORTNAME}/ \
#		http://www.lerctr.org/~ler/
# This is for release versions, leave it in please:
MASTER_SITES=	SF/courier/${PORTNAME}/${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Console based mail client with POP3/IMAP/SMAP support
WWW=		https://www.courier-mta.org/cone/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

BUILD_DEPENDS=	gnupg>0:security/gnupg
LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libcourier-unicode.so:devel/courier-unicode \
		libidn2.so:dns/libidn2
RUN_DEPENDS=	gnupg>0:security/gnupg

USES=		gettext gmake gnome iconv ldap localbase:ldflags ncurses perl5 \
		pkgconfig shebangfix ssl tar:bzip2
USE_GNOME=	libxml2

SHEBANG_FILES=	sysconftool

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--with-certdb=${PREFIX}/share/cone/rootcerts \
		--with-notice=unicode

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-D_XOPEN_SOURCE_EXTENDED

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/leaf
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mailtool
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/cone
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${STAGEDIR}${PREFIX}/sbin/cone-sysconftool
	@${RM} ${STAGEDIR}${PREFIX}/share/cone/rootcerts/.0

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
