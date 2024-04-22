PORTNAME=	ldapvi
PORTVERSION=	1.7
PORTREVISION=	7
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.lichteblau.com/download/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Tool to update LDAP entries with a text editor
WWW=		http://www.lichteblau.com/ldapvi.html

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		gmake gnome iconv ldap ncurses pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
MAKEFILE=	GNUmakefile

EXTRA_PATCHES=	${FILESDIR}/0010-renamed-getline.patch:-p2

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz \
		${DOCSDIR_REL}/manual.css ${DOCSDIR_REL}/manual.xml \
		${DOCSDIR_REL}/bg.png ${DOCSDIR_REL}/html.xsl

post-patch:
	@${REINPLACE_CMD} -e 's/-lssl/-lcrypto/' ${WRKSRC}/configure

.include <bsd.port.mk>
