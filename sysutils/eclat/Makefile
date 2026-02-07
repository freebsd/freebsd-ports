PORTNAME=	eclat
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/ \
		http://download.gnu.org.ua/pub/alpha/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Amazon EC2 command line administration tool
WWW=		https://puszcza.gnu.org.ua/software/eclat/

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2

USES=		gmake localbase tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

# Fix build with clang11
CFLAGS+=	-fcommon

PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS GDBM LDAP
OPTIONS_DEFAULT=	GDBM

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm

LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldap

post-patch:
	@${REINPLACE_CMD} -e '/DESTDIR/s,eclat\.conf,&.sample,' \
		${WRKSRC}/etc/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
