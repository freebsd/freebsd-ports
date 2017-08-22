# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	cone
PORTVERSION=	0.96.1
CATEGORIES=	mail
# This is for beta versions, leave it in please:
#MASTER_SITES=	http://www.courier-mta.org/beta/${PORTNAME}/ \
#		http://www.lerctr.org/~ler/
# This is for release versions, leave it in please:
MASTER_SITES=	SF/courier/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console based mail client with POP3/IMAP/SMAP support

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libcourier-unicode.so:devel/courier-unicode
BUILD_DEPENDS=	gpgv:security/gnupg1
RUN_DEPENDS=	gpgv:security/gnupg1

USES=		fam gettext gmake iconv localbase:ldflags ncurses perl5 shebangfix ssl tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-certdb=${PREFIX}/share/cone/rootcerts --exec-prefix=${PREFIX}
SHEBANG_FILES=	sysconftool
USE_GNOME=	libxml2
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
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
