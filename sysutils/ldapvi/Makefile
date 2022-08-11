PORTNAME=	ldapvi
PORTVERSION=	1.7
PORTREVISION=	6
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.lichteblau.com/download/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Tool to update LDAP entries with a text editor

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		gmake gnome iconv ncurses pkgconfig
USE_OPENLDAP=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile

EXTRA_PATCHES=	${FILESDIR}/0010-renamed-getline.patch:-p2

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz \
		${DOCSDIR_REL}/manual.css ${DOCSDIR_REL}/manual.xml \
		${DOCSDIR_REL}/bg.png ${DOCSDIR_REL}/html.xsl

post-patch:
	@${REINPLACE_CMD} -e 's/-lssl/-lcrypto/' ${WRKSRC}/configure

.include <bsd.port.mk>
